func timeToPrepare(drinks: [String]) -> Double {
  let timesToPrepareDrinks: [String: Double] = [
    "beer": 0.5,
    "soda": 0.5,
    "water": 0.5,
    "shot": 1.0,
    "mixed drink": 1.5,
    "fancy drink": 3.0
  ]
  return drinks.reduce(0) { $0 + timesToPrepareDrinks[$1]! }
}

func makeWedges(needed: Int, limes: [String]) -> Int {
  let limesToUse: [String: Int] = [
	"small": 6,
	"medium": 8,
	"large": 10
  ]
  var wedgesMade = 0
  var finalIndex = -1
  while wedgesMade < needed && finalIndex < limes.count - 1 {
	finalIndex += 1
	wedgesMade += limesToUse[limes[finalIndex]]!
  }
  return finalIndex+1
}

func finishShift(minutesLeft: Int, remainingOrders: [[String]]) -> [[String]] {
	var timeForEachOrder: [Double] = remainingOrders.map {timeToPrepare($0)}
	var minutesLeft = minutesLeft
	var index = 0
	while minutesLeft > 0 && index < timeForEachOrder.count {
		if minutesLeft >= timeForeachOrder[index] {
			minutesLeft -= timeForEachOrder[index]
			timeForEachOrder.remove(at: index)
			remainingOrders.remove(at: index)
		} else {
			timeForEachOrder[index] -= minutesLeft
			remainingOrders.remove(at: index)
			minutesLeft = 0
		}
	}
}

func orderTracker(orders: [(drinks: String, time: String)]) 
	-> ((beer: (first: String, last: String, total: Int)?, soda: (first: String, last: String, total: Int)?)) {
		typealias OrderResult = (first: String, last: String, total: Int)
		let beerTimes = orders.filter {$0.drinks == "beer"}.map {$0.time}.sorted()
		let sodaTimes = orders.filter {$0.drinks == "soda"}.map {$0.time}.sorted()

		var beer: OrderResult?
		if let beerTimes.first = beerTimes.first, let beerTimes.last = beerTimes.last {
			beer = (beerTimes.first, beerTimes.last, beerTimes.count)
		}

		var soda: OrderResult?
		if let sodaTimes.first = sodaTimes.first, let sodaTimes.last = sodaTimes.last {
			soda = (sodaTimes.first, sodaTimes.last, sodaTimes.count)
		}
		return (beer: beer, soda: soda)
}
