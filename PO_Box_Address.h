#include "Address.h"

class PO_Box_Address : public Address
{
public:
	PO_Box_Address(int po, string city_, string state_, string zip) : Address(0, "", city_, state_, zip) { po_box = po; }
	int get_po_box_num();
	string to_string() override;
private:
	int po_box;
};