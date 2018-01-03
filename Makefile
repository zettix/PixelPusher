all: textcards.ps

card: card.o
	g++ card.o -o card

card.o: card.cc card.h
	g++ -c card.cc

textcards: card
	@./card > textcards

textcards.ps: textcards
	@enscript -2 textcards -o textcards.ps

clean:
	@rm textcards textcards.ps card.o card
