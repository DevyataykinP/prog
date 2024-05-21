#include "varint.h"

int main()
{
    srand(time(NULL));
    uint32_t *arr=(uint32_t *)malloc(1000000*sizeof(uint32_t));
    for (int i = 0; i < 1000000;i++)
    {
        arr[i] = generate_number();
    }

    FILE *uncompressed = fopen("uncompressed.dat", "wb");
    fwrite(arr, sizeof(uint32_t), 1000000, uncompressed);
    fclose(uncompressed);

    FILE* compressed = fopen("compressed.dat", "wb");
    for (int i = 0; i < 1000000; i++) {
        uint8_t buf[4];
        size_t length = encode_varint(arr[i], buf);
        fwrite(buf, sizeof(uint8_t), length, compressed);
    }
    fclose(compressed);
    free(arr);

    printf("%lu\n%lu\n",filesize("uncompressed.dat"),filesize("compressed.dat"));

    uint32_t* uncompressed_arr = (uint32_t*)malloc(1000000 * sizeof(uint32_t));
    uncompressed = fopen("uncompressed.dat", "rb");
    fread(uncompressed_arr, sizeof(uint32_t), 1000000, uncompressed);
    fclose(uncompressed);

    compressed = fopen("compressed.dat", "rb");
    uint8_t *p = malloc(filesize("compressed.dat"));
    if (fread(p, sizeof(uint8_t), filesize("compressed.dat"), compressed) < 1) {
        printf("Error\n");
        return 0;
    }
    const uint8_t *temp = p;
    uint32_t *t = malloc(sizeof(uint32_t) * 1000000);
    for (int i = 0; i < 1000000; i++) {
        t[i] = decode_varint(&temp);
    }

    int k = 0;
    for(int i = 0; i < 1000000; i++) {
        if (t[i] != uncompressed_arr[i])
        {
            k = 1;
            break;
        }
    }
    if (k == 0)
        printf("Norm\n");
    else   
        printf("Ne norm\n");
    fclose(compressed);
    free(uncompressed_arr);
}
