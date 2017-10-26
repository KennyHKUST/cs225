/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
  if(curDim < Dim && curDim >= 0){
    if(first[curDim]!=second[curDim])
      return first[curDim] < second[curDim];
    return first < second;
  }
  return false;
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
    if(getDistance(target, potential) != getDistance(target, currentBest))
      return getDistance(target, potential) < getDistance(target, currentBest);
    return potential < currentBest;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
  points = newPoints;
  buildTree(0, points.size()-1,  0);
}
template <int Dim>
void KDTree<Dim>::buildTree(int start, int end, int curDim)
{
  if(start >= end || end < 0)
    return;

  int medium = (start + end) / 2;
  //select(start, end, curDim, medium);
  select(start, end, medium, curDim);
 //cout<<"buildTree"<<endl;
 if(start < medium - 1)
  buildTree(start, medium - 1, (curDim + 1) % Dim);
 if(end > medium + 1)
  buildTree(medium + 1, end, (curDim + 1) % Dim);

}

template <int Dim>
void KDTree<Dim>::select(int start, int end, int k, int curDim)
{
  if(start >= end)
    return;
  int split = partition(start, end, curDim);
  int len = split;
  //cout<<" split = "<<split<<" k = "<<k<<endl;
  if(len == k)
    return;
  if(k < len)
    return select(start, split - 1, k, curDim);
  return select(split + 1, end, k, curDim);
}
template <int Dim>
int KDTree<Dim>::partition(int start, int end,  int curDim)
{
  Point<Dim> pivot = points[start];
  int leftmark = start + 1;
  int rightmark = end;
  //cout<<pivot[0]<<endl;
  //cout<<pivot[1]<<endl;
  while(true){
    //cout<<"while loop"<<endl;
    while(leftmark < end && smallerDimVal(points[leftmark], pivot, curDim))
      leftmark ++;
    while(rightmark > start && smallerDimVal(pivot, points[rightmark], curDim))
      rightmark --;
    if(leftmark >= rightmark)
      break;
    else{
      Point<Dim> temp = points[leftmark];
      points[leftmark] = points[rightmark];
      points[rightmark] = temp;
    }
  }
  Point<Dim> temp = points[start];
  points[start] = points[rightmark];
  points[rightmark] = temp;
  //cout<<"rightmark = "<<rightmark<<" points[rightmark] = "<<points[rightmark]<<" points[start] = "<<points[start]<<endl;

  return rightmark;
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{

     
    return findNearestNeighborHelp(query, 0, points.size()-1, 0);
}
template <int Dim>
int KDTree<Dim>::getDistance(const Point<Dim>& query, const Point<Dim>& p) const
{
  int distance = 0;
  for(int i = 0; i < Dim; i++){
    distance += (query[i] - p[i])*(query[i] - p[i]);
  }
  return distance;
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighborHelp(const Point<Dim>& query, int start, int end, int curDim) const
{
    /**
     * @todo Implement this function!
     */
    if(start >= end)
      return points[start];
 
    int medium = (start + end)/2;
    Point<Dim> p;
    if(smallerDimVal(query, points[medium], curDim))
      p = findNearestNeighborHelp(query, start, medium-1, (curDim+1) % Dim);
    else
      p = findNearestNeighborHelp(query, medium+1, end, (curDim+1) % Dim);

    
    
    if(shouldReplace(query, p, points[medium]))
      p = points[medium];
    int distance = getDistance(query, p);

    int radius = points[medium][curDim] - query[curDim];

    if(radius*radius <= distance){
      Point<Dim> q;

      if(smallerDimVal(query, points[medium], curDim))
        q = findNearestNeighborHelp(query, medium+1, end, (curDim+1) % Dim);
      
      if(smallerDimVal(points[medium], query, curDim))
        q = findNearestNeighborHelp(query, start, medium-1, (curDim+1) % Dim);
      
      if(shouldReplace(query, p, q))
        p = q;
    }
    return p;
}



