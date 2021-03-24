struct Foo
{
};
Foo *GetFoo()
{
    static Foo foo;
    return &foo;
}

int main()
{
    int *ip;
    const int *cip;
    const int *const cicp = ip;
    auto aip = ip;
    auto acip = cip;   // const int*
    auto acicp = cicp; // also const int *const lost;

    int *ip;
    const int *cip;
    const int *const cicp = ip;
    decltype(auto) aip = ip;
    decltype(auto) acip = cip;
    decltype(auto) acicp = cicp; //const int* const

    auto fp0 = GetFoo();       //Foo*
    const auto fp1 = GetFoo(); //Foo* const
    auto const fp2 = GetFoo(); //Foo* const
    //const auto const fp3 = GetFoo(); does not compile
    const auto *fp4 = GetFoo();       //const Foo*
    auto *const fp5 = GetFoo();       //Foo* const
    const auto *const fp6 = GetFoo(); //const Foo* const
    return 0;
}