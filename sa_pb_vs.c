void	sa(t_list **a)
{
	t_list	*first;
	t_list	*second;

	if (!a || !(*a) || !((*a)->next)) // Stack'te en az iki eleman olmalı
		return;
	first = *a;
	second = (*a)->next;

	// Swap işlemi
	first->next = second->next;
	second->next = first;
	*a = second; // Yeni baş elemanı güncelle
}
void	pb(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!a || !(*a)) // Stack A boşsa işlem yapma
		return;
	temp = *a;
	*a = (*a)->next; // Stack A’nın başını güncelle

	temp->next = *b; // Stack B'nin başına ekle
	*b = temp; // Stack B'nin yeni başını güncelle
}
void	pa(t_list **b, t_list **a)
{
	t_list	*temp;

	if (!b || !(*b)) // Stack B boşsa işlem yapma
		return;
	temp = *b;
	*b = (*b)->next; // Stack B’nin başını güncelle

	temp->next = *a; // Stack A'nın başına ekle
	*a = temp; // Stack A'nın yeni başını güncelle
}
void	ra(t_list **a)
{
	t_list	*temp;
	t_list	*tail;

	if (!a || !(*a) || !((*a)->next)) // Stack'te en az iki eleman olmalı
		return;

	temp = *a; // İlk elemanı sakla
	*a = (*a)->next; // Yeni başı güncelle

	temp->next = NULL; // Eski başın bağlantısını kopar

	// Stack'in sonuna ekle
	tail = *a;
	while (tail->next)
		tail = tail->next;
	tail->next = temp;
}
void	rra(t_list **a)
{
	t_list	*prev;
	t_list	*tail;

	if (!a || !(*a) || !((*a)->next)) // Stack'te en az iki eleman olmalı
		return;

	prev = NULL;
	tail = *a;

	// Stack'in sonuna kadar git
	while (tail->next)
	{
		prev = tail;
		tail = tail->next;
	}
	prev->next = NULL; // Yeni sonu güncelle
	tail->next = *a; // Eski sonu başa taşı
	*a = tail; // Yeni başı güncelle
}



