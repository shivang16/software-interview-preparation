class Book{
    private:
        string bookId;
        string bookTitle;
        string author;
        set <BookCategory> bookCategory;
        int bookCost;
        int lateFee;
        int numberOfDaysToBeKept;
        int quantity;
        int quantityLeft;
    public:
        // gettersAndSetters of the above -> Except bookId
};

class BookItem{
    private: 
        string bookItemId;
        string bookId;
        BookStatus bookStatus;
        Location bookLocation;
}

enum BookStatus{
    BOOKED,
    AVAILAIBLE
}

enum BookCategory{
    FICTIONAL,
    NON_FICTIONAL
};

class Rack{
    private: 
        string RackId;
        int quantity;
        int quantity_left;
        vector <Location> location;
};
class Location{
    private:
        BookItem bookItem;
        int LocationId;
}
class Address{
    private: 
        string street1;
        string pinCode;
        string city;
        string country;
}
class Person{
    private: 
        string firstName;
        string lastName;
        Address address;
        int contactNo;
};

enum MemberType{
    NORMAL,
    EXLUSIVE;
}
class Member extends Person{
    private: 
        string memberId;
        string barCodeId; // Will be generated using member id
        enum MemberType;
        vector <Booking>;
        
        Booking    createBooking(bookItem) {
                 // Check if the member already has limit on the booking   
                 // CreatePayment -> if successful -> return BookingId otherwise null
                }

        returnBook(){
            // Check for the fine
            // if fine
                // MakePayment(fine)
            // return 'cannot be returned' 
        }

        
    
};


class Library{
    vector <Racks> allRacks;
    vector <Members> members;
    vector <BookItem> bookItems; 

    vector <books> searchBooks(title, author, bookCategory){}
                

    Notification sendNotitifcation(){
        //Search all the booking to be send
        
    }

    makePayment(memberId,amount){

    }

}

class Booking{
    private: 
        string bookingId;
        Date bookingDate;
        map <bookItem,submisionDate> booking;
        int totalCost;
        BookingStatus bookingStatus;
}

class Notification{
    string message,
    date notificationDate;
}

