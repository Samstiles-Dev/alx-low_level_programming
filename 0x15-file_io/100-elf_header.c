#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>


void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void check_elf(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);

/**
 * check_elf - A function that checks if a file is an ELF file.
 * @e_ident: An array pointer that contains the ELF magic numbers.
 *
 * Description: exit code 98 - If the file is not an ELF file
 */
void check_elf(unsigned char *e_ident)
{
	/* Index  Variable declaration */
	int index_322;

	for (index_322 = 0; index_322 < 4; index_322++)
	{
		if (e_ident[index_322] != 127 &&
		    e_ident[index_322] != 'E' &&
		    e_ident[index_322] != 'L' &&
		    e_ident[index_322] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: This is Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - A function that prints the magic numbers of an ELF header.
 * @e_ident: An array pointer that contains the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *e_ident)
{
	/* Index  Variable declaration */
	int index_322;

	printf(" Magic: ");

	for (index_322 = 0; index_322 < EI_NIDENT; index_322++)
	{
		printf("%02x", e_ident[index_322]);

		if (index_322 == EI_NIDENT - 1)
		{
			printf("\n");
		}
		else
		{
			printf(" ");
		}
	}
}

/**
 * print_class - A function that prints the class of an ELF header.
 * @e_ident: An array pointer that contains the ELF class.
 */
void print_class(unsigned char *e_ident)
{
    /* Printf */
    printf(" Class: ");
    
    if (e_ident[EI_CLASS] == ELFCLASSNONE)
    {
        printf("none\n");
    }
    else if (e_ident[EI_CLASS] == ELFCLASS32)
    {
        printf("ELF32\n");
    }
    else if (e_ident[EI_CLASS] == ELFCLASS64)
    {
        printf("ELF64\n");
    }
    else
    {
        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}


/**
 * print_data - A function that prints the data of an ELF header.
 * @e_ident: An array pointer that contains the ELF class.
 */
void print_data(unsigned char *e_ident)
{
    /* Printf */
    printf(" Data: ");
    
    if (e_ident[EI_DATA] == ELFDATANONE)
    {
        printf("none\n");
    }
    else if (e_ident[EI_DATA] == ELFDATA2LSB)
    {
        printf("2's complement, little endian\n");
    }
    else if (e_ident[EI_DATA] == ELFDATA2MSB)
    {
        printf("2's complement, big endian\n");
    }
    else
    {
        printf("<unknown: %x>\n", e_ident[EI_DATA]);
    }
}


/**
 *  * print_version - A function that prints the version of an ELF header.
 *   * @e_ident: An array pointer that contains the ELF version.
 *    */
void print_version(unsigned char *e_ident)
{
    printf(" Version: %d", e_ident[EI_VERSION]);
    
    if (e_ident[EI_VERSION] == EV_CURRENT)
    {
        printf(" (current)\n");
    }
    else
    {
        printf("\n");
    }
}

/**
 * print_osabi - A function that prints the OS/ABI of an ELF header.
 * @e_ident: An array pointer that contains the ELF version.
 */
void print_osabi(unsigned char *e_ident)
{
    printf(" OS/ABI: ");
    
    /* unsigned char osabi = e_ident[EI_OSABI]; */
    
    if (e_ident[EI_OSABI] == ELFOSABI_NONE)
    {
        printf("UNIX - System V\n");
    }
    else if (e_ident[EI_OSABI] == ELFOSABI_HPUX)
    {
        printf("UNIX - HP-UX\n");
    }
    else if (e_ident[EI_OSABI] == ELFOSABI_NETBSD)
    {
        printf("UNIX - NetBSD\n");
    }
    else if (e_ident[EI_OSABI] == ELFOSABI_LINUX)
    {
        printf("UNIX - Linux\n");
    }
    else if (e_ident[EI_OSABI] == ELFOSABI_SOLARIS)
    {
        printf("UNIX - Solaris\n");
    }
    else if (e_ident[EI_OSABI] == ELFOSABI_IRIX)
    {
        printf("UNIX - IRIX\n");
    }
    else if (e_ident[EI_OSABI] == ELFOSABI_FREEBSD)
    {
        printf("UNIX - FreeBSD\n");
    }
    else if (e_ident[EI_OSABI] == ELFOSABI_TRU64)
    {
        printf("UNIX - TRU64\n");
    }
    else if (e_ident[EI_OSABI] == ELFOSABI_ARM)
    {
        printf("ARM\n");
    }
    else if (e_ident[EI_OSABI] == ELFOSABI_STANDALONE)
    {
        printf("Standalone App\n");
    }
    else
    {
        printf("<unknown: %x>\n", e_ident[EI_OSABI]);
    }
}


/**
 * print_abi - A function that prints the ABI version of an ELF header.
 * @e_ident: An array pointer that contains the ELF ABI version.
 */
void print_abi(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - A function that prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: An array pointer that contains the ELF class.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
    if (e_ident[EI_DATA] == ELFDATA2MSB)
    {
        e_type >>= 8;
    }

    printf(" Type: ");
    
    if (e_type == ET_NONE)
    {
        printf("NONE (None)\n");
    }
    else if (e_type == ET_REL)
    {
        printf("REL (Relocatable file)\n");
    }
    else if (e_type == ET_EXEC)
    {
        printf("EXEC (Executable file)\n");
    }
    else if (e_type == ET_DYN)
    {
        printf("DYN (Shared object file)\n");
    }
    else if (e_type == ET_CORE)
    {
        printf("CORE (Core file)\n");
    }
    else
    {
        printf("<unknown: %x>\n", e_type);
    }
}


/**
 * print_entry - A function that prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: An array pointer that contains the ELF class.
 */

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
    printf(" Entry point address: ");
    
    switch (e_ident[EI_DATA])
    {
    case ELFDATA2MSB:
        e_entry = ((e_entry << 8) & 0xFF00FF00) |
                  ((e_entry >> 8) & 0xFF00FF);
        e_entry = (e_entry << 16) | (e_entry >> 16);
        break;
    }
    
    switch (e_ident[EI_CLASS])
    {
    case ELFCLASS32:
        printf("%#x\n", (unsigned int)e_entry);
        break;
    default:
        printf("%#lx\n", e_entry);
        break;
    }
}


/**
 * close_elf - A function that closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: This cannot close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - A main function that displays the information contained in the
 * ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 * the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o_322, r_322;

	o_322 = open(argv[1], O_RDONLY);
	if (o_322 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o_322);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r_322 = read(o_322, header, sizeof(Elf64_Ehdr));
	if (r_322 == -1)
	{
		free(header);
		close_elf(o_322);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(o_322);
	return (0);
}
