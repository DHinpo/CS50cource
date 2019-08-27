#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    float n = atoi(argv[1]);
    float p = atof(argv[1]);

    if ((argc != 4) && ((n <= 0) || (n > 100)))
        {
            fprintf(stderr, "Usage: ./resize n infile outfile\n");
            return 1;
        }
    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];
    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
        {
            fprintf(stderr, "Could not open %s.\n", infile);
            return 2;
        }
    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
        {
            fclose(inptr);
            fprintf(stderr, "Could not create %s.\n", outfile);
            return 3;
        }
    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    BITMAPFILEHEADER bf_resize;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    BITMAPINFOHEADER bi_resize;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
            {
                fclose(outptr);
                fclose(inptr);
                fprintf(stderr, "Unsupported file format.\n");
                return 4;
            }
    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    if (n >= 1)
        {
            p = 1;
        }
    else
        {
            n = p;
        }
    bi_resize.biWidth = bi.biWidth *n;
    bi_resize.biHeight = bi.biHeight *n;
    int padding_out = (4 - (bi_resize.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bf_resize.bfType = 0x4d42;	
    bf_resize.bfOffBits = 54;
    bf_resize.bfReserved2 = bf.bfReserved2;
    bi_resize.biSize = 40;
    bi_resize.biBitCount = 24;
	bi_resize.biPlanes = 1;
    bi_resize.biCompression = 0;
    bi_resize.biXPelsPerMeter = bi.biXPelsPerMeter;
    bi_resize.biYPelsPerMeter = bi.biYPelsPerMeter;
    bi_resize.biClrUsed = 0;
    bi_resize.biClrImportant = 0;
    bi_resize.biSizeImage = ((bi_resize.biWidth *sizeof(RGBTRIPLE)  + padding_out) * abs(bi_resize.biHeight));
    // write outfile's BITMAPFILEHEADER
    bf_resize.bfSize = bi_resize.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    fwrite(&bf_resize, sizeof(BITMAPFILEHEADER), 1, outptr);
    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_resize, sizeof(BITMAPINFOHEADER), 1, outptr);
    int inptr_line = ((bi.biWidth * sizeof(RGBTRIPLE)) + padding);
    // iterate over infile's scanlines
    if (n >=1)  // вставляю іф для флоат!
        {
            for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
                {
                    for (int l = 0; l < n ; l++ )
                        {
                            // iterate over pixels in scanline
                            for (int j = 0; j < bi.biWidth; j++)
                                {
                                    // temporary storage
                                    RGBTRIPLE triple;
                                    // read RGB triple from infile
                                    fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                                    for (int x = 0; x < n ; x++ )
                                        {
                                            // write RGB triple to outfile
                                            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                                        }
                                }
                            // skip over padding, if any
                            fseek(inptr, padding, SEEK_CUR);
                            // then add it back (to demonstrate how)
                            for (int k = 0; k < padding_out; k++)
                                {
                                    fputc(0x00, outptr);
                                }
                            fseek(inptr, -inptr_line, SEEK_CUR);
                        }
                    fseek(inptr, inptr_line, SEEK_CUR);
                }
        }
    else   
       {
        int l = 1/n;
        for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i = i +l)   //i = i +l
            {
                // iterate over pixels in scanline
                for (int j = 0; j < bi.biWidth; j++) 
                    {
                        // temporary storage
                        RGBTRIPLE triple;
                        // read RGB triple from infile
                        fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                        if (j %2 == 0)   //оце додав!!!
                        // write RGB triple to outfile
                            {
                                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                            }
                    }
                // skip over padding, if any
                fseek(inptr, padding, SEEK_CUR);
                // then add it back (to demonstrate how)
                for (int k = 0; k < padding_out; k++)
                    {
                        fputc(0x00, outptr);
                    }
                fseek(inptr, inptr_line, SEEK_CUR);  
            }
        }
    // close infile
    fclose(inptr);
    // close outfile
    fclose(outptr);
    // success
    return 0;
}