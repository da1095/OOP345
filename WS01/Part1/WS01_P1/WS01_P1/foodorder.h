#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H

namespace sdds
{

	double g_taxrate;
	double g_dailydiscount;

	class FoodOrders
	{
		char* food_order[10];
		char* food[25];
		double food_price;
		bool flag;

		public:
			FoodOrders();
			~FoodOrders();
			bool read();
			void display();
	};
}

#endif