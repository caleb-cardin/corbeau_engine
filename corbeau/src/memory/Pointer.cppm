// Created by cabo_ on 12/29/2023.
//
module;

export module Pointer;

export namespace corbeau::memory {



    template<class C>
    class U_ptr {
    public:
        U_ptr() : _ptr(nullptr) {}

        explicit U_ptr(C* ptr) : _ptr(ptr) {}

        U_ptr(const U_ptr&) = delete;
        U_ptr(U_ptr&&) = delete;

        ~U_ptr() { delete _ptr; }


        auto operator=(const U_ptr &)->U_ptr = delete;
        auto operator=(U_ptr&&)->U_ptr& = delete;

        auto operator->()const-> const C* {return _ptr;}


        auto get()->C* {return _ptr;}
        auto get()const->const C* {return _ptr;}

        auto invalidate()->void
        {
            _ptr = nullptr;
        }
        auto reset(C* ptr)->void
        {
            _ptr = ptr;
        }
        auto reset(const C* ptr)->void
        {
            _ptr = ptr;
        }

        friend static auto makeUnique()->U_ptr;

    private:
        C* _ptr = nullptr;
    };

    template<class C>
    auto makeUnique()->U_ptr<C>
    {
        return {new C};
    }



}