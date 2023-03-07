tmp = R;
		R = R->next;
		for(int i=0;i<floor(ll.size/2);i++){
			tmp->next = L;
			tmp = tmp->next;
			L = L->next;
			if (R!=NULL){
				tmp->next = R;
				tmp = tmp->next;
				R = R->next;
			}