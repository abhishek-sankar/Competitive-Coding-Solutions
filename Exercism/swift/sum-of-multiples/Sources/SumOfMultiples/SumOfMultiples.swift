//Solution goes in Sources
struct SumOfMultiples {
	static func toLimit(_ limit: Int, inMultiples: [Int]) -> Int {
		return (0 ..< limit)
			.filter{ x in
				inMultiples.contains {x.isMultiple(of: $0)}
			}.reduce(0, +)
	}
}
