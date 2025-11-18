#include <iostream>
#include <vector>
#include <math.h> 


class Bond{

    public:

        Bond(double rates,double cash_flows,double face_values){

            this ->Bond_rates= rates;
            this ->cash_flow=cash_flows;
            this ->face_value=face_values;



    }

    double value_of_bond(int number_years){

        double Bond_value=0.0;

        for (int i=1; i<number_years; i++){

            Bond_value+= cash_flow*exp(-Bond_rates*i);

        

        }

        Bond_value+=(face_value+cash_flow)*exp(-Bond_rates*number_years);

        return Bond_value;


    }

      double duration_of_bond(int number_years){

        double Bond_duration=0.0;

        for (int i=1; i<number_years; i++){

            Bond_duration+= cash_flow*exp(-Bond_rates*i)*i;

        

        }

        Bond_duration+=(face_value+cash_flow)*exp(-Bond_rates*number_years)*number_years;

        auto duration=Bond_duration/value_of_bond(number_years);

        return duration;

    }

    double variation_bond_price(double change_rates,int number_years){

        double change_bond;

        change_bond=-change_rates*duration_of_bond(number_years)*value_of_bond(number_years);

        return change_bond;

    }


    private:
        double Bond_rates;
        double cash_flow;
        double face_value;


};


int main(){

    Bond bond1(0.10,10,100);

    auto val=bond1.value_of_bond(10);

    std::cout<<"The value of the bond is "<<val<<" dollars"<<std::endl;

    auto dur = bond1.duration_of_bond(1000);

    std::cout<<"The duration of the bond is "<<dur<<" years"<<std::endl;

    auto change=bond1.variation_bond_price(0.05,10);

    std::cout<<"With a change of rates of "<<0.05<<", the bond value changes by "<<change<<" dollars"<<std::endl;



    return 0;

}