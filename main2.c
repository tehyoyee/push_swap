
void	ft_nodeprint_a(t_node *node1)
{
	t_node	*tmp1;

	printf("==========================\n");
	printf("==========================\n");
	printf("Stack A \n");
	if (!node1)
		return ;
	tmp1 = node1;
	while (node1)
	{
		printf("value : %d		order : %lu\n", node1->value, node1->order);
		if (node1->next == tmp1)
			break;
		node1 = node1->next;
	}
	printf("==========================\n");
	printf("==========================\n");
}
void	ft_nodeprint_b(t_node *node2)
{
	t_node	*tmp2;

	printf("Stack B \n");
	printf("==========================\n");
	printf("==========================\n");
	if (!node2)
		return ;
	tmp2 = node2;
	while (node2)
	{
		printf("node->value : %d\n", node2->value);
		if (node2->next == tmp2)
			break;
		node2 = node2->next;
	}
	printf("==========================\n");
	printf("==========================\n");
}
void	ft_nodeprint_r(t_node *node1, t_node *node2)
{
	t_node	*tmp1;
	t_node	*tmp2;

	node1 = node1->prev;
	tmp1 = node1;
	if (!node1)
		return ;
	printf("==================================\n");
	printf("========= R Stack A ============\n");
	printf("==================================\n");
	while (tmp1 != node1->prev)
	{
		printf("node->value : %d\n", node1->value);
		node1 = node1->prev;
	}
	printf("node->value : %d\n", node1->value);
	printf("==================================\n");
	printf("==================================\n");
	printf("==================================\n");
	printf("========= R Stack B ============\n");
	printf("==================================\n");
	if (!node2)
		return ;
	node2 = node2->prev;
	tmp2 = node2;
	while (tmp2 != node2->prev)
	{
		printf("node->value : %d\n", node2->value);
		node2 = node2->prev;
	}
	printf("node->value : %d\n", node2->value);
	printf("==================================\n");
	printf("==================================\n");
}
