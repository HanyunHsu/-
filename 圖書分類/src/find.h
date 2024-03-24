template <class RandomAccessIterator, class Compare>
std::vector<Publication *> find(RandomAccessIterator begin, RandomAccessIterator end, const std::string & value, Compare comp) {
    std::vector<Publication *> result;

    for (RandomAccessIterator i = begin; i != end; i++) {
        if (comp(*i, value)){
            result.push_back(*i);
        }
    }

    return result;
}