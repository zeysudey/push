static int	find_max_bit(t_list **stack)
{
	int		max;
	t_list	*current;
	int		bit_count;

	if (!stack || !(*stack))
		return (0);
	
	max = (*stack)->index;
	current = *stack;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}

	bit_count = 0;
	while ((max >> bit_count) != 0) // En büyük indeksin kaç bit uzunluğunda olduğunu bul
		bit_count++;

	return (bit_count);
}

static void	bit_sort(t_list **a, t_list **b, int bit)
{
	int	n;

	if (!a || !(*a))
		return;

	n = (*a)->index; // İlk elemanın index değerini al

	if (!((n >> bit) & 1)) // Eğer bit değeri 0 ise, Stack B'ye gönder
		pb(b, a);
	else
		ra(a); // Eğer bit değeri 1 ise, Stack A içinde döndür
}

void	radix_sort(t_list **a, t_list **b)
{
	int	i;
	int	j;
	int	max_bits;
	int	size;

	size = ft_lstsizepush(a);
	get_next_min(a); // Bağlı listedeki index değerlerini belirle

	i = 0;
	max_bits = find_max_bit(a); // Maksimum kaç bit kullanılacağını hesapla

	while (i < max_bits) // Bit sayısı kadar iterasyon yap
	{
		j = 0;
		while (j < size) // Tüm elemanları işle
		{
			bit_sort(a, b, i); // i'nci bit'e göre elemanları Stack B'ye taşı
			j++;
		}
		while ((ft_lstsizepush(b)) > 0) // Stack B'deki elemanları geri al
			pa(b, a);
		i++;
	}
}
