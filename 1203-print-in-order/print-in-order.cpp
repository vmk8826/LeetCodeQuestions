class Foo {
    mutex m1;
    condition_variable cv;
    int turn;
public:
    Foo() {
        turn=0;
    }

    void first(function<void()> printFirst) {
        printFirst();
        turn=1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex>lock(m1);
        while(turn!=1){
            cv.wait(lock);
        }
        printSecond();
        turn=2;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex>lock(m1);
        while(turn!=2){
            cv.wait(lock);
        }
            printThird();
            m1.unlock();
    }
    
};