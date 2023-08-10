#include<bits/stdc++.h>

class Address{
    private: 
        string street, 
        string city,
        string state,
        string pinCode;
}

abstract class MainSystem{
    city;
    
}

class CityMainSystem extends MainSystem{
    List <Cinema> cinemas; // string is cityName
    list <MovieSchedule> allMovieSchedule; // string is cityName
    list <Customer> customer;

    list <MovieSchedule> searchShow(title,language,genre,releaseDate){
        // Search for allMoviewSchedule
    }
};

class Cinema{
    private: 
        string name;
        Address address;
        List <Halls> halls;
        List <MovieSchedule> movieScheule;
        List <SeatSchedule> seatSchedule;

        Ticket bookTicket(Date,totalSeats,MovieSchedule, Hall, Customer){
            showSeatingArrangement(MoviewScheule);

            bookSeat();
        };

        List <seats> showSeatingArrangement(moviewScheule){

        }
};

class Halls{
    private: 
        string hallId;
        string hallNumberName;
        Movie currentMovie;
};

class Seats{
    private: 
        string seatId;
        SeatType seatType;
        string seatNumber;
};

enum SeatType{
    'Normal',
    'Luxury'
}
class Movie{
    string movieName;
    date releaseDate;
    list <Genre> genre;
    Language language; // We assume we are just having single language for the movie
    int duration;
};

enum Language{
    'English',
    'Hindi',
}
enum Genre{
    'Action',
    'Romantic'
}

class MovieSchedule{
    Date startDate;
    Cinema cinemaDetail;
    Movie movieDetail;
};

class SeatSchedule extends MovieSchedule{
    Seats seatDetail;
    BookingStatus status;
    Hall hallDetail;

    bool bookSeat(){
        bookingStatus = booked;
        generateTicket();
    }
    bool cancelBooking(){
        bookingStatus = free;
    }
}

enum BookingStatus{
    'FREE',
    'BOOKED',
    'NOT_AVAILAIBLE'
}

class Customer{
    // Customer details

    List <Tickets> ticket;
};

class Ticket{
    List <SeatSchedule> seatScheudle;
    PaymentStatus paymentStatus;
    date bookingTime;

    generateTicket();
};

enum PaymentStatus{
    'PAID',
    'UNPAID'
}
abstract class Payment{

};

class CreditCard extends Payment{

};

class Cash extends Payment{

};