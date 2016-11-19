#include "PO_Box_Address.h"

int PO_Box_Address::get_po_box_num()
{
	return po_box;
}

string PO_Box_Address::to_string()
{
	string result;

	result = "P.O. Box " + Str_conversion::to_string(get_po_box_num()) + "\n"
		+ get_city() + ", " + get_state() + " " + get_zip_code() + "\n";

	return result;
}