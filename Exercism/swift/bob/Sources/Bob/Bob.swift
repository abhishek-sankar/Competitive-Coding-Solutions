import Foundation

struct Bob {
	static func hey(_ input: String) -> String {
		let isSilent: Bool = input.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty
		let isShouting: Bool = input == input.uppercased() && input != input.lowercased()
		let isQuestion: Bool = input.hasSuffix("?")

		if isSilent{
			return "Fine. Be that way!"
		} else if isQuestion && isShouting {
			return "Calm down, I know what I'm doing!"
		} else if isQuestion {
			return "Sure."
		} else if isShouting {
			return "Whoa, chill out!"
		} else {
			return "Whatever."
		}
	}
}