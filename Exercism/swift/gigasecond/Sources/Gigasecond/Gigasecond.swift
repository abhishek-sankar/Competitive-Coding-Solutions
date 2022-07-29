import Foundation

func Gigasecond(from: String) -> String? {

	let dateFormatter = DateFormatter()
	dateFormatter.locale = Locale(identifier: "en_US_POSIX")
	dateFormatter.dateFormat = "yyyy-MM-dd'T'HH:mm:ss"
	guard let givenDate = dateFormatter.date(from: from) else { return nil }
    let dateAfterGigasecond = Date(timeInterval: 1_000_000_000, since: givenDate)
	return dateFormatter.string(from: dateAfterGigasecond)
}