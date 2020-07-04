class A {
    static int counter;
    int my_number;
public:
    A()
    {
        my_number = counter;
        counter++;
    }
    int get_number() const
    {
        return my_number;
    }
};
int A::counter = 0;
int static_counter_of_instances()
{
    A a, b, c, d, e;
    A x[10];
    cout << "a number " << a.get_number() << endl;
    cout << "b number " << b.get_number() << endl;
    cout << "c number " << c.get_number() << endl;
    cout << "d number " << d.get_number() << endl;
    cout << "e number " << e.get_number() << endl;
    for (int i = 0; i < 10; i++)
        cout << "x[" << i << "] number " << x[i].get_number() << endl;
    return 0;
}