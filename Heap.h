class Heap {
private:
    std::function<bool(T, T)> cmp_;
    std::vector<T> mas_;
    void Up(size_t id) {
        while (id != 0 and cmp_(mas_[id], mas_[(id - 1) / 2])) {
            Swap(mas_[id], mas_[(id - 1) / 2]);
            id = (id - 1) / 2;
        }
    }

    void Down(size_t id) {
        while (2 * id + 1 < mas_.size()) {
            size_t max_chield = 2 * id + 1;
            if (max_chield + 1 < mas_.size() and cmp_(mas_[max_chield + 1], mas_[max_chield])) {
                ++max_chield;
            }
            if (!cmp_(mas_[max_chield], mas_[id])) {
                break;
            }
            Swap(mas_[id], mas_[max_chield]);
            id = max_chield;
        }
    }

public:
    Heap(std::function<bool(T, T)> cmp) : cmp_(cmp) {
    }
    void Push(T elem) {
        mas_.push_back(elem);
        Up(mas_.size() - 1);
    }

    T Pop() {
        T value = mas_[0];
        mas_[0] = mas_.back();
        mas_.pop_back();
        Down(0);
        return value;
    }

    T Top() {
        return mas_[0];
    }

    bool Empty() {
        return mas_.empty();
    }
};
