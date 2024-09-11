total_cards = 52
kings = 4
spades = 13
king_of_spades = 1

king_or_spade = kings + spades - king_of_spades
# print("\n")

# print("The king OR Spade is:",king_or_spade)

king_nor_spade = total_cards - king_or_spade

# print("The King NOR Spade is:",king_nor_spade)

pb= king_nor_spade / total_cards

print("\n")
print("The Probability of it Being Neither a King NOR a Spade:",pb)
print(f"The Probability of it Being Neither a King NOR a Spade: {pb:.2f}")
print("\n")