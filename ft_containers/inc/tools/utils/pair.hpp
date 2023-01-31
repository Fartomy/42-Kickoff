#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
	template <class T1, class T2> struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		first_type first;
		second_type second;

		pair() : first(), second() {};
		pair( const T1& f, const T2& s ) : first(f), second(s) {}; // Bir probleme rastlanirsa f ve s yi initilaze etme!

		template<class U1, class U2> pair(const pair<U1, U2>& pr) : first(pr.first), second(pr.second){};

		pair& operator=(const pair& pr)
		{
			this->first = pr.first;
			this->second = pr.second;
			return ( *this );
		}
	};
	template<class T1, class T2> void swap(pair<T1,T2>& f, pair<T1,T2>& s) { f = s; }
	template<class T1, class T2> pair<T1,T2> make_pair(T1 f, T2 s) { return pair<T1,T2>(f,s); }
	template<class T1, class T2> inline bool operator==(const pair<T1,T2>& f, const pair<T1,T2>& s) { return ( f.first == s.first && f.second == s.second ); }
	template<class T1, class T2> inline bool operator!=(const pair<T1,T2>& f, const pair<T1,T2>& s) { return !( f == s ); }
	template<class T1, class T2> inline bool operator<(const pair<T1,T2>& f, const pair<T1,T2>& s) { return ( (f.first < s.first) || (!(s.first < f.first) && f.second < s.second )); }
	template<class T1, class T2> inline bool operator<=(const pair<T1,T2>& f, const pair<T1,T2>& s) { return !( s < f ); }
	template<class T1, class T2> inline bool operator>(const pair<T1,T2>& f, const pair<T1,T2>& s) { return ( s < f ); }
	template<class T1, class T2> inline bool operator>=(const pair<T1,T2>& f, const pair<T1,T2>& s) { return !( f < s ); }
};

// https://cplusplus.com/reference/utility/pair/?kw=pair

#endif