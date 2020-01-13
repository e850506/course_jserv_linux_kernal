// @ created by unknowntpo at 2020.1.12 (Sun)
// @ ref: https://hackmd.io/@sysprog/c-trick?type=view#%E5%96%84%E7%94%A8-GNU-extension-%E7%9A%84-typeof
// @ title: 你所不知道的C語言：技巧篇
// Prefer to return a value rather than modifying pointers
/*
* This encourages immutability,
* cultivates pure functions,
* and makes things simpler and easier to understand. 
* It also improves safety by eliminating the possibility of a NULL argument.
*/

// unnecessary mutation (probably), and unsafe
void drink_mix(Drink * const drink, Ingredient const ingr) {
	assert(drink);
	color_blend(&(drink->color), ingr.color);
	drink->alcohol += ingr.alcohol;
}

// immutability rocks, pure and safe functinos everywhere
Drink drink_mix(Drink const drink, Ingredient const ingr) {
	return (Drink) {
		.color = color_blend(drink.color, ingr.color),
		.alcohol = drink.alcohol + ingr.alcohol
	};
}
