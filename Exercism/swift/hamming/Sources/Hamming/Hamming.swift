class Hamming {
	static func compute(_ dnaStrand: String, against: String) -> Int?{
		var hammingDistance = 0
		if dnaStrand.count != against.count {
			return nil
		}
		for i in 0..<dnaStrand.count {
			if dnaStrand[dnaStrand.index(dnaStrand.startIndex, offsetBy: i)] != against[against.index(against.startIndex, offsetBy: i)] {
				hammingDistance += 1
			}
		}
	return hammingDistance
	}
}
