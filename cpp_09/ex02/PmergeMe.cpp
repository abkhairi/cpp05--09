/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:51:08 by abkhairi          #+#    #+#             */
/*   Updated: 2024/10/30 14:45:30 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


//------------------------------------------------------------------container_vector---------------------------------------------------------------------------------------------

PmergeMe::PmergeMe()
{}


bool ft_number(std::string s)
{
    size_t i = 0;
    if (s[0] == '+')
        i++;
    for (; s.length() > i; i++ )
    {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

void print_vec(std::vector<int> v)
{
    for(size_t i =0; v.size() > i; i++)
        std::cout << v[i ] <<" "; 
}

void merge(std::vector<int> &vec, int start, int mid, int end)
{
    int tmp[end - start + 1];
    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end)
    {
        if (vec[i] > vec[j])
            tmp[k++] = vec[j++];
        else
            tmp[k++] = vec[i++];
    }
    while(j <= end)
        tmp[k++] = vec[j++];
    while (i <= mid)
        tmp[k++] = vec[i++];
    for(i = start; i <= end; i++)
        vec[i] = tmp[i - start];
}


int binarySearch(std::vector<int> &v, int target)
{
    int left = 0;
    int right = v.size() - 1;
    int mid = 0;

    while (left <= right)
    {
        mid = (left + right) / 2; 
        if (v[mid] == target)
            return mid;
        else if (v[mid] < target)
            left = mid + 1;
        else if (v[mid] > target)
            right = mid - 1;
    }
    return left;
}


void merge_sort(std::vector<int> &tmp1_2, int start , int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(tmp1_2, start, mid);
        merge_sort(tmp1_2, mid + 1, end);
        merge(tmp1_2, start, mid, end);
    }
}

void repalce_vec_pair(std::vector<int> &v, std::string flag,std::vector<std::pair<int, int> >  &pair)
{
    if (flag == "first")
    {
        std::vector<std::pair <int, int> >::iterator it_pair;

        for (it_pair = pair.begin(); it_pair != pair.end(); ++it_pair)
            v.push_back(it_pair->first);
    }
    else if (flag == "second")
    {
        std::vector<std::pair <int, int> >::iterator it_pair2;

        for (it_pair2 = pair.begin(); it_pair2 != pair.end(); ++it_pair2)
            v.push_back(it_pair2->second);
    }
}

void makepair(std::vector<int> &vec, std::vector<int>& tmp_vec1, std::vector<int>& tmp_vec2)
{
    std::vector<std::pair<int, int> > pair;
    for (size_t i =0; vec.size() > i ; i += 2)
    {
        if (vec[i] > vec[i + 1])
            std::swap(vec[i], vec[i + 1]);
        if (i+1 != vec.size())
            pair.push_back(std::make_pair(vec[i], vec[i + 1]));
    }

    repalce_vec_pair(tmp_vec1,"first", pair);
    repalce_vec_pair(tmp_vec2,"second", pair);
    merge_sort(tmp_vec1, 0, tmp_vec1.size() - 1);

    int posInsert;
    for (size_t i = 0; i < tmp_vec2.size(); i++)
    {
        posInsert = binarySearch(tmp_vec1, tmp_vec2[i]); 
        tmp_vec1.insert(tmp_vec1.begin() + posInsert, tmp_vec2[i]);
    }
    if (vec.size() % 2 != 0)
    {
        posInsert = binarySearch(tmp_vec1, vec[vec.size()]);
        tmp_vec1.insert(tmp_vec1.begin() + posInsert, vec[vec.size()]);
    }
    vec = tmp_vec1;
}

double PmergeMe::sorted_vector(std::vector<int> &vec)
{
    std::vector<int> tmp_vec1;
    std::vector<int> tmp_vec2;

    std::clock_t start = std::clock(); //std::clock() : Cette fonction renvoie le temps CPU actuel utilisé par le programme depuis son démarrage
    makepair(vec, tmp_vec1, tmp_vec2);
    std::clock_t end  = std::clock();

    double time_ = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000; //le facteur * 1000 convertit le temps écoulé de secondes en millisecondes.
    return(time_);
}

PmergeMe::PmergeMe(const PmergeMe &ob)
{
    (void)ob;   
}

PmergeMe& PmergeMe::operator=(const PmergeMe &ob)
{
    (void)ob;
    return(*this);
}

PmergeMe::~PmergeMe()
{

}

//------------------------------------------------------------------container_Deque---------------------------------------------------------------------------------------------


void print_vec(std::deque<int> v)
{
    for(size_t i =0; v.size() > i; i++)
        std::cout << v[i ] <<" "; 
}

void merge(std::deque<int> &deq, int start, int mid, int end)
{
    int tmp[end - start + 1];
    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end)
    {
        if (deq[i] > deq[j])
            tmp[k++] = deq[j++];
        else
            tmp[k++] = deq[i++];
    }
    while(j <= end)
        tmp[k++] = deq[j++];
    while (i <= mid)
        tmp[k++] = deq[i++];
    for(i = start; i <= end; i++)
        deq[i] = tmp[i - start];
}


int binarySearch(std::deque<int> &d, int target)
{
    int left = 0;
    int right = d.size() - 1;
    int mid = 0;

    while (left <= right)
    {
        mid = (left + right) / 2; 
        if (d[mid] == target)
            return mid;
        else if (d[mid] < target)
            left = mid + 1;
        else if (d[mid] > target)
            right = mid - 1;
    }
    return left;
}


void merge_sort(std::deque<int> &deq1, int start , int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(deq1, start, mid);
        merge_sort(deq1, mid + 1, end);
        merge(deq1, start, mid, end);
    }
}

void repalce_vec_pair(std::deque<int> &d, std::string flag, std::deque<std::pair<int, int> >  &pair)
{
    if (flag == "first")
    {
        std::deque<std::pair <int, int> >::iterator it_pair;

        for (it_pair = pair.begin(); it_pair != pair.end(); ++it_pair)
            d.push_back(it_pair->first);
    }
    else if (flag == "second")
    {
        std::deque<std::pair <int, int> >::iterator it_pair2;

        for (it_pair2 = pair.begin(); it_pair2 != pair.end(); ++it_pair2)
            d.push_back(it_pair2->second);
    }
}

void makepair(std::deque<int> &dequee, std::deque<int>& deq1, std::deque<int>& deq2)
{
    std::deque<std::pair<int, int> > pair;
    for (size_t i =0; dequee.size() > i ; i += 2)
    {
        if (dequee[i] > dequee[i + 1])
            std::swap(dequee[i], dequee[i + 1]);
        if (i+1 != dequee.size())
            pair.push_back(std::make_pair(dequee[i], dequee[i + 1]));
    }

    repalce_vec_pair(deq1,"first", pair);
    repalce_vec_pair(deq2,"second", pair);
    merge_sort(deq1, 0, deq1.size() - 1);

    int posInsert;
    for (size_t i = 0; i < deq2.size(); i++)
    {
        posInsert = binarySearch(deq1, deq2[i]); 
        deq1.insert(deq1.begin() + posInsert, deq2[i]);
    }
    if (dequee.size() % 2 != 0)
    {
        posInsert = binarySearch(deq1, dequee[dequee.size()]);
        deq1.insert(deq1.begin() + posInsert, dequee[dequee.size()]);
    }
    dequee = deq1;
}

double PmergeMe::sorted_deque(std::deque<int> &deq)
{
    std::deque<int> tmp_deq1;
    std::deque<int> tmp_deq2;

    std::clock_t start = std::clock(); //std::clock() : Cette fonction renvoie le temps CPU actuel utilisé par le programme depuis son démarrage
    makepair(deq, tmp_deq1, tmp_deq2);
    std::clock_t end  = std::clock();

    double time_ = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000; //le facteur * 1000 convertit le temps écoulé de secondes en millisecondes.
    return(time_);
}

