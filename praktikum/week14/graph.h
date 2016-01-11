int countIsolatedVertices(Graph<T>& gr)
    {
        LList<T> possible;
        gr.g.IterStart();
        elem_link1<T>* curr = gr.g.Current();
        while(curr->link != NULL)
        {
            LList currVert = curr->inf;
            if(currVert.length() == 0)
            {
                possible.toEnd(curr->inf);
            }
        }
    }
