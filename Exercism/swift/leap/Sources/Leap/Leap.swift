//Solution goes in Sources
struct Year {
	let calendarYear: Int
	var isLeapYear: Bool {
		let isDivisibleBy4 = calendarYear % 4 == 0
		let isDivisibleBy100 = calendarYear % 100 == 0
		let isDivisibleBy400 = calendarYear % 400 == 0
		return isDivisibleBy4 && (!isDivisibleBy100 || isDivisibleBy400)
	}
}