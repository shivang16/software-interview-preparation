/*
1. Multiple floors
2. Multiple entry and exit points
3. Customers can collect a parking ticket from the entry points and can pay the parking fee at the exit points on their way out.
4. Customers can pay the tickets at the automated exit panel or to the parking attendant
5. Customers can pay via both cash and credit cards.
6. Customers should also be able to pay the parking fee at the customer’s info portal on each floor. If the customer has paid at the info portal, they don’t have to pay at the exit.
7. The system should not allow more vehicles than the maximum capacity of the parking lot. If the parking is full, the system should be able to show a message at the entrance panel and on the parking display board on the ground floor.
8. Each parking floor will have many parking spots. The system should support multiple types of parking spots such as Compact, Large, Handicapped, Motorcycle, etc.
9. The Parking lot should have some parking spots specified for electric cars. These spots should have an electric panel through which customers can pay and charge their vehicles.
10. The system should support parking for different types of vehicles like car, truck, van, motorcycle, etc.
11. Each parking floor should have a display board showing any free parking spot for each spot type.
12. The system should support a per-hour parking fee model. For example, customers have to pay $4 for the first hour, $3.5 for the second and third hours, and $2.5 for all the remaining hours.
*/
class Address{
    string city;
    string steet;
    string pinCode;
    //....
}

class ParkingLot{
    string parkingLotId;
    Address address;
    List <ParkingFloor> parkingFloors;
    map <parkingSpots,int> maximumCapacity;
    List <Customers> customers;
    List <Attendants> attendats;
    int totalFareCollected; 
    string MessageOnGroundFloor; // Shows the message on the ground floor everytime
    

};

class ParkingFloor{
    int floorNumber;
    List <EntryPoints> entryPoints;
    List <ExitPoints> exitPoints;
    List <ParkingSpots> parkingSpots;
    List <customerInfoPortal> customerInfoPortal; 

};

class ParkingSpots{
    string ParkingSpotId;
    VehicleType parkingSpotSupported; // If electric spot is supported then it will have charhing option
    bool isAvailaible;

    bool checkAvailibitiy() // return true if parking spot is availaible

};

enum VechileType{
    'Compact',
    'Large',
    'Handicapped',
    'Motorcycle',
    'electricVehicle'
};

map <VechileType, map <int,int>> parkingFare;

class Gate{

};

class EntryPoints extends Gate{
    string entryPointId;
    

    ParkingSpot checkParkingSpots(VechileType vechile){
        // Checks if parking spot if available for given vechicle and return its spot   

        // Call generate Ticket
    } 



    Ticket generateTicket(Customer){
        // checkAvailibitiy -> Return null if no availibilty
    }
};

class ExitPoints extends Gate, extends Payment{
    string exitPoints; 

    collectPayment(Ticket ticket){
        // If already paid then open gate
        // Else collect payment and open gate
    }  
};

class Payment{

    // Collect payment method
    abstract method collectPayment();

    calculateTotalFare(Ticket ticket){
        // Current Tiimr and vechile type
    }
};

class CustomerInfoPortal extends Payment{
    string customerInfoPortalId;

    collectPayment(Ticket ticket){
        // Collect payment
    }

}
class Account{
    // AccountDetails
    name,
    Address address,
    // Other details
}

class Customer extends Account{
    string customerId;

    //Request for spot
}

class Attendant extends Account, Payment{
    string attendantId;


    collectPayment(){

    }
}

class Ticket{
    string TicketId;
    Date entryDate,
    VechileType vechicleTyle;
    string customerId;
    bool isPaid;
}