//Solution goes in Sources

class Grains {

	static var total: UInt64 {
		return UInt64.max
	}

	static func square(_ squareId: Int) throws -> UInt64 {
		if squareId > 64 {
			throw GrainsError.inputTooHigh("Input[\(squareId)] invalid. Input should be between 1 and 64 (inclusive)")
		} else if squareId < 1 {
			throw GrainsError.inputTooLow("Input[\(squareId)] invalid. Input should be between 1 and 64 (inclusive)")
		}
		return 1 << (squareId - 1)
	}

	enum GrainsError: Error {
		case inputTooHigh(String)
		case inputTooLow(String)
	}

}

