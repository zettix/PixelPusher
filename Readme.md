# Pixel Pusher. (C) 2018 Sean Brennan
##  All rights reserved.

## Pixel Pusher is a game for two to six players.

## Object
Collect points by creating pixel images on the game board.
Be the first collect 11 victory points to win.

## Game components
 * The game board is a simple grid, 12x12.
 * The pieces are "pixels", about 100.
 * A deck of cards.

The deck has three types of cards: Victory cards, sprite cards, and special cards. Victory cards have:
 * The cost of the card.
 * The victory points when matched.
 * The name of the card.
 * The image to match.

Sprite cards have:
 * The cost of the card.
 * The name of the card.
 * The pixels to place.

Special cards have:
 * The cost of the card.
 * The name of the card.
 * Text describing the action.

## Game play
On each player's turn, they may do only ONE of the following:
 * Take two pixels from the bank and put them in your stash.
 * Remove two pixels from the board.  Put it in the bank.
 * Place up to two pixels from your stash on the board.
 * Play a card.  Normally this is an image match and the player earns points and removes pixels.  For special cards, the user may discard cards, place pixels, or other action.
 * Buy a card with pixels from your stash.  Replace the bought card with one from the deck.
 * Discard a card from their hand for 8 pixels.

Play proceeds clockwise from the first player.  The first player to earn 11
victory points wins the game.  Total victory points are what the player has
earned by matching patters minus what they have left in their hand.

Some cards with with other cards, like Mirror, Almost There, and Burn In, described below.
But they are only used with one other card and do not stack.

## Player limitations
 * Players are limited to 8 pixels.
 * Players are limited to 4 cards.

## Setup
Each player starts with 0 pixels.
The deck is shuffled and one card per player is turned up plus one.
For 4 players turn over 5 cards.

## Cards
There are two types of cards: Pattern matching cards with victory points and
special cards. Pattern matching cards are low resolution pixel images,
from 5x5 down to 3x3.  There are 38 such cards.  The special cards are:
 * Almost there.  You can claim the image despite being one pixel off, but the score is one less victory point.  This card can only be played with a victory card.
 * Mirror.  Images can be rotated only, mirror allows a mirrord version to match.  This card can only be played with a victory card.
 * I changed my mind.  Discard one of your cards and draw from the deck.  This card can only be played with a victory card.
 * Burn in.  When placing pixels, if a pixel is already there, stack another on top.  This card can only be played with a sprite card or in conjuction with placing 2 pixels.
 * Sprites.  Lines, disjoint pixels, things to speed up drawing.

## Card Management
If, in a round, no player buys any cards, discard the first and deal a replacement
from the deck.

## End
---
