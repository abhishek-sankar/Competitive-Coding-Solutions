// @ts-check

/**
 * Determine how many cards of a certain type there are in the deck
 *
 * @param {number[]} stack
 * @param {number} card
 *
 * @returns {number} number of cards of a single type there are in the deck
 */
export function cardTypeCheck(stack, card) {
  let cardCount = 0
  stack.forEach(element => {
	if (element === card) {
		cardCount++
	}
  });
  return cardCount
}

/**
 * Determine how many cards are odd or even
 *
 * @param {number[]} stack
 * @param {boolean} isEven the type of value to check for - odd or even
 * @returns {number} number of cards that are either odd or even (depending on `type`)
 */
export function determineOddEvenCards(stack, isEven) {
  return stack.filter(value => {
	if (isEven) {
		return value % 2 === 0
	} else {
		return value % 2 !== 0
	}
  }).length
}
