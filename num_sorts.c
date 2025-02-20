void	sort_two(t_list **a)
{
	if ((*a)->val > (*a)->next->val)
		sa(a);
}

void	sort_three(t_list **a)
{
	if ((*a)->val > (*a)->next->val && (*a)->val > (*a)->next->next->val)
		ra(a);
	if ((*a)->val > (*a)->next->val)
		sa(a);
	if ((*a)->next->val > (*a)->next->next->val)
	{
		rra(a);
		if ((*a)->val > (*a)->next->val)
			sa(a);
	}
}

void	sort_four(t_list **a, t_list **b)
{
	while ((*a)->val != minn(a)) // En küçük elemanı bulana kadar döndür
		ra(a);
	pb(b, a); // En küçük elemanı Stack B'ye at
	
	sort_three(a); // Kalan üç elemanı sırala
	
	pa(b, a); // Stack B'deki en küçük elemanı geri al
}

void	sort_five(t_list **a, t_list **b)
{
	while ((*a)->val != minn(a)) // En küçük elemanı bulana kadar döndür
		ra(a);
	pb(b, a); // En küçük elemanı Stack B'ye at
	
	while ((*a)->val != minn(a)) // Bir sonraki en küçük elemanı bulana kadar döndür
		ra(a);
	pb(b, a); // Onu da Stack B'ye at
	
	sort_three(a); // Kalan üç elemanı sırala
	
	pa(b, a); // Stack B'deki en küçük elemanı geri al
	pa(b, a); // İkinci en küçük elemanı geri al
}
