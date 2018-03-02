#ifndef OFFER_H_INCLUDED
#define OFFER_H_INCLUDED

class offer()
{
private:

 int offerId; //uniquely identifies an offer
 int flightNumber; //related to flight number in Flight class, the offer can be on a certain flight or on any flight
 string offerType; //miles or number of lights or
 int discountAmount; //related to discount in Ticket class

 public:
     void set_OID(int a)
     {
         offerid=a;
     }
     void set_FlightN(int a)
     {
         flightNumber=a;
     }
     void set_offerT(string a)
     {
         offerType=a;
     }
     void set_discount(int a)
     {
         discountAmount=a;
     }
     void set_info(int id,int FN,string ofr,int dis)
     {
         set_OID=id; set_FlightN(FN); set_offerT(ofr); set_discount(dis);
     }

};


#endif // OFFER_H_INCLUDED
