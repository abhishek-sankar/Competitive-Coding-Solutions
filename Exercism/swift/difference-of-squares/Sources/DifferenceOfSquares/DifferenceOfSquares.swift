//Solution goes in Sources
class Squares {
	let sumOfSquares: Int
	let squareOfSum: Int
	let differenceOfSquares: Int

	init(_ n: Int) {
		squareOfSum = (1...n).reduce(0, +) * (1...n).reduce(0, +)
		sumOfSquares = n * (n + 1) * (2 * n + 1) / 6
		differenceOfSquares = squareOfSum - sumOfSquares
	}
}