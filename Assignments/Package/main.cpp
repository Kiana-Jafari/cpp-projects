#include <iostream>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

using namespace std;

int main()
{
    static const double sizeLimit{5000.0};

    PersonInfo s1{"John Doe", "123 A St", "Boston", "MA", "02115"};
    PersonInfo r1{"Mary Smith", "85 B Ave", "Miami", "FL", "33101"};
    
    Package package1{s1, r1, 10, 0.5, 10, 5, 2};
    package1.setTrackingID("TRK-001-BOS");
    package1.updateStatus("In Transit");

    cout 
    << package1.toString()
    << "\nOversized: " << (package1.isOversized(sizeLimit) ? "Yes" : "No")
    << "\nFinal total cost: $" << package1.calculateCost()
    << "\n\n";

    // ----------

    PersonInfo s2{"John Smith", "10 Short Rd", "Denver", "CO", "80202"};
    PersonInfo r2{"Sara Chen", "99 Long Rd", "Seattle", "WA", "98101"};

    Package package2{s2, r2, 0.1, 0.01, 4, 3, 1};
    package2.setTrackingID("TRK1002");
    package2.updateStatus("Delivered");

    cout
    << "---------------------\n"
    << package2.toString()
    << "\nOversized: " << (package2.isOversized(sizeLimit) ? "Yes" : "No")
    << "\nFinal total cost: $" << package2.calculateCost()
    << "\n\n";

    // ----------
    
    PersonInfo s3{"Bob Gray", "50 Main St", "Austin", "TX", "73301"};
    PersonInfo r3{"Emma Stone", "400 Lake Dr", "Chicago", "IL", "60007"};

    TwoDayPackage package3{s3, r3, 20, 0.4, 2.50, 20, 15, 10};
    package3.setTrackingID("TRK1003");
    package3.updateStatus("Out for Delivery");

    cout
    << "---------------------\n"
    << package3.toString()
    << "\nOversized: " << (package3.isOversized(sizeLimit) ? "Yes" : "No")
    << "\nFinal total cost: $" << package3.calculateCost()
    << "\n\n";

    // Update data
    package3.setWeight(150);
    package3.setCostPerWeight(0.2);
    package3.setFlatFee(10);
    package3.setDimensions(60, 40, 30);
    package3.updateStatus("Delivered");

    cout
    << "---------------------\n"
    << package3.toString()
    << "\nOversized: " << (package3.isOversized(sizeLimit) ? "Yes" : "No")
    << "\nUpdated final total cost: $" << package3.calculateCost()
    << "\n\n";

    // ----------

    PersonInfo s4{"Chris Pine", "72 Oak St", "Orlando", "FL", "32789"};
    PersonInfo r4{"Luke Miles", "101 Pine St", "Phoenix", "AZ", "85001"};

    OvernightPackage package4{s4, r4, 12, 0.3, 0.2, 12, 6, 4};
    package4.setTrackingID("TRK-004-OVR");
    package4.updateStatus("In Transit - Port St. Lucie Hub");

    cout
    << "---------------------\n"
    << package4.toString()
    << "\nOversized: " << (package4.isOversized(sizeLimit) ? "Yes" : "No")
    << "\nFinal total cost: $" << package4.calculateCost()
    << "\n\n";

    // Updated conditions
    package4.setWeight(8);
    package4.setCostPerWeight(0.1);
    package4.setFeePerWeight(0.9);
    package4.setDimensions(6, 4, 3);
    package4.updateStatus("Delivered");

    cout
    << "---------------------\n"
    << package4.toString()
    << "\nOversized: " << (package4.isOversized(sizeLimit) ? "Yes" : "No")
    << "\nUpdated final total cost: $" << package4.calculateCost()
    << "\n\n";

}
