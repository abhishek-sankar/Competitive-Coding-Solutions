//Solution goes in Sources

struct ETL {
	static func transform(_ old: [Int: [String]]) -> [String: Int] {
		var new = [String: Int]()
		for (score, letters) in old {
			for letter in letters {
				new[letter.lowercased()] = score
			}
		}
		return new
	}
}