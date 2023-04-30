#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // iterate over pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // calculate average colour
            int average; 
            average = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0); 
            
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // create temporary buffer
    RGBTRIPLE temp[height][width];
    
    // iterate over pixels
    for (int i = 0; i < height; i++)
    {
        // set count to 0
        int j = 0; 
        {
            // iterate horizontally 
            for (int g = width - 1; g >= 0 ; g--, j++)
            {
                temp[i][j] = image[i][g];
            }
        }
    }
    
    // copy to final image
    for (int i = 0; i < height; i++)
    { 
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // create a temporary buffer
    RGBTRIPLE temp[height][width];
    
    // iterate over pixels
    for (int i = 0; i < height; i++)
    { 
        for (int j = 0; j < width; j++)
        {
            // check all neighbouring pixels
            int count = 0;
            int row[] = {i - 1, i, i + 1};
            int col[] = {j - 1, j, j + 1};
            float sumR = 0, sumB = 0, sumG = 0;
            
            
            // iterate over neighbouring pixels
            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    int currR = row[r];
                    int currC = col[c];
                    
                    // validate
                    if (currR >= 0 && currR < height && currC >= 0 && currC < width)
                    {
                        // add each colour
                        sumR += image[currR][currC].rgbtRed;
                        sumB += image[currR][currC].rgbtBlue;
                        sumG += image[currR][currC].rgbtGreen;
                        count ++;
                        
                    }
                }
                
                // assign each colour to the temporary buffer
                temp[i][j].rgbtRed = round(sumR / count);
                temp[i][j].rgbtBlue = round(sumB / count);
                temp[i][j].rgbtGreen = round(sumG / count);
            }
        }
        
    }
    // copy to the final image
    for (int i = 0;  i< height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
            
        }
        
    }
   
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[width][height];
    
    // create Gx and Gy matrixes 
    int Gx[3][3] =
    {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
        
    };
    
    int Gy[3][3] =
    {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };
    
    // loop through each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j  = 0; j < width; j++)
        {
            int row[] = { i - 1, i, i + 1};
            int col[] = { j - 1, j, j + 1};
            
            float VsumR = 0, VsumG = 0, VsumB = 0;
            float HsumR = 0, HsumG = 0, HsumB = 0;
            
            // loop through the neighbouring pixels
            for (int r = 0; r < 3 ; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    int CurrR = row[r];
                    int CurrC = col[c];
                    
                    // validate
                    if (CurrR >= 0 && CurrR < height && CurrC >= 0 && CurrC < width)
                    {
                        VsumR += Gx[r][c] * image[CurrR][CurrC].rgbtRed;
                        VsumG += Gx[r][c] * image[CurrR][CurrC].rgbtGreen;
                        VsumB += Gx[r][c] * image[CurrR][CurrC].rgbtBlue;
                        
                        HsumR += Gy[r][c] * image[CurrR][CurrC].rgbtRed;
                        HsumG += Gy[r][c] * image[CurrR][CurrC].rgbtGreen;
                        HsumB += Gy[r][c] * image[CurrR][CurrC].rgbtBlue;
                        
                    }
                    
                }
            }
            
            // apply the formula
            int FRed = round(sqrt(VsumR * VsumR + HsumR * HsumR));
            int FGreen = round(sqrt(VsumG * VsumG + HsumG * HsumG)); 
            int FBlue = round(sqrt(VsumB * VsumB + HsumB * HsumB));
            
            // cap each colour to 255
            if (FRed > 255)
            {
                FRed = 255; 
                
            }
            
            if (FGreen > 255) 
            {
                FGreen = 255;
                
            }
            
            if (FBlue > 255) 
            {
                FBlue = 255;
                
            }
            
            // assign the final colour to each pixel
            temp[i][j].rgbtRed = FRed;
            temp[i][j].rgbtGreen = FGreen;
            temp[i][j].rgbtBlue = FBlue;
            
        }
        
    }
    
    // copy to final image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
            
        }
        
    }
    return;
    
}
