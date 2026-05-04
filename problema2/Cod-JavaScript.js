/**
 * Valida si una cadena C cumple con el estándar Forsyth-Edwards Notation (FEN).
 * @param {string} c - La cadena a validar.
 * @returns {boolean} - True si es válida, false de lo contrario.
 */
function validarFEN(c) {
    if (typeof c !== 'string') return false;

    // 1. Expresión regular para validación estructural básica
    // Campo 1: Piezas | Campo 2: Turno | Campo 3: Enroque | Campo 4: Al paso | Campo 5: 50 mov | Campo 6: Mov total
    const fenRegex = /^([rnbqkpRNBQKP1-8]{1,8}\/){7}[rnbqkpRNBQKP1-8]{1,8}\s[wb]\s(K?Q?k?q?|-)\s([a-h][36]|-)\s\d+\s\d+$/;

    if (!fenRegex.test(c)) return false;

    // 2. Validación semántica del campo de piezas (cada fila debe sumar exactamente 8 casillas)
    const piezas = c.split(' ')[0];
    const filas = piezas.split('/');

    for (let fila of filas) {
        let sumaCasillas = 0;
        for (let char of fila) {
            if (/\d/.test(char)) {
                sumaCasillas += parseInt(char); // Es un número de casillas vacías
            } else {
                sumaCasillas += 1; // Es una pieza
            }
        }
        if (sumaCasillas !== 8) return false; // Cada fila debe tener 8 casillas
    }

    return true;
}

// --- Pruebas ---
const casos = [
    "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", // Posición inicial (Válida)
    "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1", // Tras 1. e4 (Válida)
    "rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2", // Inválida (en passant incoherente pero sintaxis correcta)
    "invalid string" // Inválida
];

casos.forEach(c => console.log(`Cadena: ${c}\n¿Es FEN válido?: ${validarFEN(c)}\n`));