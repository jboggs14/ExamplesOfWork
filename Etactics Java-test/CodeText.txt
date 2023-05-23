import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class CardDeck{
    public static void main(String args[]){

        List<Card> DeckOfCards = new ArrayList<Card>();  //make an array list of cards
        for (Suit suit : Suit.values())
        {
            for (Rank rank : Rank.values())
            {
                DeckOfCards.add(new Card(rank, suit)); //adds the cards to the array list, going by suit first, then rank
            }
        }

        System.out.println(DeckOfCards.size() + " cards are in the deck.");
        Collections.shuffle(DeckOfCards); //collection has a shuffle function, which I can use to shuffle the deck
        System.out.println("Shuffled Deck:\n");
      for (Card card : DeckOfCards)
      {
       System.out.print(card); //prints out the shuffled deck
      }


      System.out.println("\n\nSorted by Rank:\n");
      Collections.sort(DeckOfCards, new SortByRank()); //Using the Collections.sort function, I can grab my objet (DeckOfCards), and create my own way to sort them.
      for (Card card : DeckOfCards)
      {
       System.out.print(card); //prints out the newly sorted deck
      }
      
      Collections.shuffle(DeckOfCards); //shuffles again

      System.out.println("\n\nSorted by Suit and Rank:\n");
      Collections.sort(DeckOfCards, new SortBySuitAndRank()); //Same as previous sort function, but with a different sorting method
      for (Card card : DeckOfCards)
      {
       System.out.print(card); //prints out the newly sorted deck
      }
    }
}


class Card{ //Card class
    private Rank rank;  //card rank (i.e. Two, Five, Queen, Ace)
    private Suit suit;  //card suit (i.e. Diamonds, Clubs, Hearts, Spades)

    public Card(Rank rank, Suit suit)     //when cards created, give it a rank and suit
    {
        this.rank = rank;        
        this.suit = suit;
    }

    public String toString(){           //turns card info into a string to print the cards info
        return rank + " of " + suit + "\n";
    }

    public Rank GetRank(){  //return Card's rank
        return rank;
    }

    public Suit GetSuit(){      //return Card's suit
        return suit;
    }
}

enum Rank{  //possible card Ranks 
    Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace
}

 enum Suit{ //possible card Suits
    Diamonds, Hearts, Spades, Clubs
}

class SortByRank implements java.util.Comparator<Card>{ //sorts cards by their rank
    public int compare(Card a, Card b) //compares card a and card b
    {
     return a.GetRank().compareTo(b.GetRank()); // going off of ordinal value within the enum Rank: 
     //example "Two" is before "Jack", so we'll say Two's ordinal value is 0, while Jack's is 9. This function will check if the Card a and
     //b's ordinal value of Rank is the same. If a's Rank ordinal value is less than b's it'll return a negative integer. If the same it will return 0
     //If a's Rank ordinal value is greater, it will return a positive integer. This is what the Collections.sort(DeckOfCards, new SortByRank) uses to know what
     //card to use next 
    }
}

class SortBySuitAndRank implements java.util.Comparator<Card>{    // sorts the cards by suit and rank
   public int compare(Card a, Card b) //compares card a and card b
   {
    int isSuit = a.GetSuit().compareTo(b.GetSuit()); // using same logic as above
    if (isSuit != 0)
    {
        return isSuit; //if suits are not the same, returns isSuit
    }
    else
    {
        return a.GetRank().compareTo(b.GetRank());  //If suits are the same, the cards will then compare ranks in the same way as above.
    }
   }
   
}
