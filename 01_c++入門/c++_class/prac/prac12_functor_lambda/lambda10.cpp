 #include <cstdio>
  
 template<class t_t>
 void exec_f1(t_t f)
 {
     std::printf("f:%u %p\n",sizeof(f), &f);
     f(4);
 }
  
 template<class t_t>
 void exec_f2(t_t f)
 {
     std::printf("f:%u %p\n",sizeof(f), f);
     (*f)(4);
     f->operator()(4);
 }
  
 template<class t_t>
 void exec_f3(t_t &f)
 {
     std::printf("f:%u %p\n",sizeof(f), &f);
     f(4);
 }
  
 int main()
 {
     int x = 3, xx=10,xxx=12;
     auto f = [&x,&xx,&xxx](int y){
         std::printf("足し算：%d\n", x+y);
         ++x;
     };
     
     std::printf("f: %p\n", &f);
     
     exec_f1(f);
     exec_f1(f);
     
     exec_f2(&f);
     exec_f2(&f);
     
     exec_f3(f);
     exec_f3(f);
     
 //    exec_f2(&[](int y){std::printf("y:%d\n",y);});
 //    exec_f3([](int y){std::printf("y:%d\n",y);});
     
     return 0;
 }