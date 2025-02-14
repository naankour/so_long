#include <stdio.h>

void	is_ber(char	*file_path)
{
	int	i;

	i = 0;
	while (file_path[i] != '\0')
		i++;
	if (i <= 4)
	{
		ft_printf("Error : Invalid file. Extension must be '.ber'.\n");
		return ;
	}
	if (file_path[i - 1] == 'r' && file_path[i - 2] == 'e'
			&& file_path[i - 3] == 'b' && file_path[i - 4] == '.')
			return ;
	ft_printf("Error : Invalid file. Extension must be '.ber'.\n");
}
int	main()
{
	char	*file_path = ".ber";
	is_ber(file_path);
	return (0);
}