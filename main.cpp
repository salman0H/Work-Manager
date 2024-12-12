#include <iostream>
#include "string"
using namespace std;
class worker
{
    friend istream &operator >>(istream &in , worker &obj);
    friend ostream &operator <<(ostream &out, worker &obj);
//public:
private:
    string name;
    string family;
public:
    worker(string _name = "N",string _family = "F")
    {
        name = _name;
        family = _family;
    }
    void setname(string _name)
    {
        name = _name;
    }
    void setfamily(string _family)
    {
        family = _family;
    }
    string getname()
    {
        return name;
    }
    string gatfamily()
    {
        return family;
    }
    virtual void print()
    {
        cout <<endl<< name << '\t' << family <<endl;
    }
    virtual double getsalary() = 0;
};
istream &operator >>(istream &in,worker &obj)
{
    cout << "enter name : ";
    in >> obj.name;
    cout <<"enter family : ";
    in >> obj.family;
    return in;
}
ostream &operator <<(ostream &out,worker &obj)
{
    obj.print();
    return out;
}
//----------------------------------------------------------------------------------------------------------------------
class salaried_worker : public worker
{
    friend istream &operator >>(istream &in , salaried_worker &obj);
    friend ostream &operator <<(ostream &out, salaried_worker &obj);
//public:
private:
    double salary;
public:
    salaried_worker()
    {

    }
    salaried_worker(string _name,string _family,double _salary) : worker(_name,_family)
    {
        setsalary(_salary);
    }
    void setsalary(double _salary)
    {
        if(_salary > 0)
        {
            salary = _salary;
        }else{
            salary = 0;
        }
    }
    double getsalary()
    {
        return  salary;
    }
    virtual void print()
    {
        cout << "\nsalaried worker : "<< salary ;
        worker :: print();
    }
};
istream &operator >>(istream &in,salaried_worker &obj)
{
    string _name,_family;
    cout << "enter name:";
    in >> _name;
    obj.setname(_name);
    cout << "enter family: ";
    in >> _family;
    obj.setfamily(_family);
    cout << "enter salary: ";
    in >> obj.salary;
    return in;
}
ostream &operator <<(ostream &out,salaried_worker &obj)
{
    obj.print();
    return out;
}
//----------------------------------------------------------------------------------------------------------------------
class hourly_worker : public worker
{
    friend istream &operator >>(istream &in , hourly_worker &obj);
    friend ostream &operator <<(ostream &out, hourly_worker &obj);
//public:
private:
    int hour;
    double work_per_hour;
public:
    hourly_worker()
    {

    }
    hourly_worker(string _name,string _family,double _work_per_hour,int hour) : worker(_name,_family)
    {
        sethour(hour);
        setwph(_work_per_hour);
    }
    void sethour(int _hour)
    {
        if(_hour > 0)
        {
            hour = _hour;
        }else{
            hour = 0;
        }
    }
    void setwph(double _w_p_h)
    {
        if(_w_p_h > 0)
        {
            work_per_hour = _w_p_h;
        }else{
            _w_p_h = 0;
        }
    }
    int gethour()
    {
        return hour;
    }
    double getwph()
    {
        return work_per_hour;
    }
    virtual void print()
    {
        cout << "\nhourly salary : " << getsalary() ;
        worker :: print();
    }
    virtual double getsalary()
    {
        return (hour * work_per_hour);
    }
};
istream &operator >>(istream &in,hourly_worker &obj)
{
    string _name,_family;
    cout << "enter name:";
    in >> _name;
    obj.setname(_name);
    cout << "enter family: ";
    in >> _family;
    obj.setfamily(_family);
    cout << "enter hour : ";
    in >> obj.hour;
    cout <<"enter work per hour : ";
    in >> obj.work_per_hour;
    return in;
}
ostream &operator <<(ostream &out,hourly_worker &obj)
{
    obj.print();
    return out;
}
//----------------------------------------------------------------------------------------------------------------------
class commision_worker : public worker
{
    friend istream &operator >>(istream &in , commision_worker &obj);
    friend ostream &operator <<(ostream &out, commision_worker &obj);
//public:
private:
    double rate;
    int quantity;
public:
    commision_worker()
    {

    }
    commision_worker(string _name,string _family,double _rate,int _quantity) : worker(_name,_family)
    {
        setrate(_rate);
        setquantity(_quantity);
    }
    void setrate(double _rate)
    {
        if(_rate > 0 && _rate <= 1)
        {
            rate = _rate;
        }else{
            rate = 0;
        }
    }
    void setquantity(int _quantity)
    {
        if(_quantity > 0)
        {
            quantity = _quantity;
        }else{
            quantity = 0;
        }
    }
    double getrate()
    {
        return rate;
    }
    int getquantity()
    {
        return quantity;
    }
    virtual double  getsalary()
    {
        return (rate * quantity);
    }
    virtual void print()
    {
        cout << "\ncommision worker salary : "<<getsalary();
        worker :: print();
    }
};
istream &operator >>(istream &in,commision_worker &obj)
{
    string _name,_family;
    cout << "enter name:";
    in >> _name;
    obj.setname(_name);
    cout << "enter family: ";
    in >> _family;
    obj.setfamily(_family);
    cout <<"enter rate : ";
    in >> obj.rate;
    cout << "enter quantity : ";
    in >> obj.quantity;
    return in;
}
ostream &operator <<(ostream &out, commision_worker &obj)
{
    obj.print();
    return out;
}
//----------------------------------------------------------------------------------------------------------------------
class boss : public salaried_worker
{
    friend istream &operator >>(istream &in , boss &obj);
    friend ostream &operator <<(ostream &out, boss &obj);
//public:
private:
    double extra;
public:
    boss()
    {

    }
    boss(string _name,string _family,double _extra,double salary) : salaried_worker(_name,_family,salary)
    {
        setextra(_extra);
    }
    void  setextra(double _extra)
    {
        extra = _extra;
    }
    double getextra()
    {
        return extra;
    }
    virtual void print()
    {
        cout << "\nsalary of boss : "<<getsalary();
        worker :: print();
    }
    virtual double getsalary()
    {
        double sum;
        sum = salaried_worker::getsalary();
        return (sum + extra);
    }

};
istream &operator >>(istream &in,boss &obj)
{
    string  _name,_family;
    double _salary;
    cout << "enter name:";
    in >> _name;
    obj.setname(_name);
    cout << "enter family: ";
    in >> _family;
    obj.setfamily(_family);
    cout << "enter salary: ";
    in >> _salary;
    obj.setsalary(_salary);
    cout << "enter extra : ";
    in >> obj.extra;
    return in;
}
ostream &operator <<(ostream &out,boss &obj)
{
    obj.print();
    return out;
}
//----------------------------------------------------------------------------------------------------------------------

int main() {
    for( ; ; )
    {
        int number;
        cout <<"select your worker type:"<<endl;
        cout <<"\t1.salaried worker.\n"<<
                "\t2.hourly worker.\n"<<
                "\t3.commission worker.\n"<<
                "\t4.you are BOSS.\n"<<
                "\tenter your type ";

        cin >> number;
        if(number == 1)
        {
            salaried_worker worker1;
            cin >> worker1;
            cout << worker1;
            break;
        }else if(number == 2)
        {
            hourly_worker worker2;
            cin >> worker2;
            cout << worker2;
            break;
        }else if(number == 3)
        {
            commision_worker worker3;
            cin >> worker3;
            cout << worker3;
            break;
        }else if(number == 4)
        {
            boss worker4;
            cin >> worker4;
            cout << worker4;
            break;
        }


    }
    return 0;
}
