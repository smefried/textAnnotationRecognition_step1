#include "bitmap.h"
#include "Position.h"

#include <random>
#include <vector>
#include <queue>

using namespace std;

std::random_device rd;
std::mt19937_64 gen {rd()};
std::uniform_int_distribution<> red_dist(1, 255);
std::uniform_int_distribution<> blue_dist(1, 255);
std::uniform_int_distribution<> green_dist(1, 255);

Pixel get_random_pixel(){
    Pixel randomPixle(red_dist(gen),blue_dist(gen),green_dist(gen));
    return randomPixle;
}

bool isWhite(Pixel rgb){
    return (rgb.red + rgb.green + rgb.blue == 765);
}

bool isBlack(Pixel rgb){
return (rgb.red + rgb.green + rgb.blue == 0);
}

vector <Position> addFrom(vector <vector <Pixel> > & bmp, Position pos){
    Pixel usedRGB = Pixel(255,255,255);
    queue <Position> pixelsProcessed;
    vector <Position> pixelsFound;
    if (isBlack(bmp[pos.x][pos.y])){
        pixelsProcessed.push(pos);
        while (!pixelsProcessed.empty()) {
            Position frontPos = pixelsProcessed.front();
            Position upP(frontPos.x-1,frontPos.y);
            Position downP(frontPos.x+1,frontPos.y);
            Position leftP(frontPos.x,frontPos.y-1);
            Position rightP(frontPos.x,frontPos.y+1);
            pixelsFound.push_back(frontPos);
            if (frontPos.x > 0 && frontPos.x < bmp.size() - 1) {
                if (frontPos.y > 0 && frontPos.y < bmp[0].size() - 1) {
                    if (isBlack(bmp[frontPos.x - 1][frontPos.y])) {
                        bmp[frontPos.x - 1][frontPos.y] = usedRGB;
                        pixelsProcessed.push(upP);
                    }
                    if (isBlack(bmp[frontPos.x + 1][frontPos.y])) {
                        bmp[frontPos.x + 1][frontPos.y] = usedRGB;
                        pixelsProcessed.push(downP);
                    }
                    if (isBlack(bmp[frontPos.x][frontPos.y - 1])) {
                        bmp[frontPos.x][frontPos.y - 1] = usedRGB;
                        pixelsProcessed.push(leftP);
                    }
                    if (isBlack(bmp[frontPos.x][frontPos.y + 1])) {
                        bmp[frontPos.x][frontPos.y + 1] = usedRGB;
                        pixelsProcessed.push(rightP);
                    }
                } else if (frontPos.y == 0){
                        if (isBlack(bmp[frontPos.x-1][frontPos.y])) {
                            bmp[frontPos.x-1][frontPos.y] = usedRGB;
                            pixelsProcessed.push(upP);
                        }
                        if (isBlack(bmp[frontPos.x+1][frontPos.y])) {
                            bmp[frontPos.x+1][frontPos.y] = usedRGB;
                            pixelsProcessed.push(downP);
                        }
                        if (isBlack(bmp[frontPos.x][frontPos.y+1])) {
                            bmp[frontPos.x][frontPos.y + 1] = usedRGB;
                            pixelsProcessed.push(rightP);
                        }
                } else if (frontPos.y == bmp[0].size() - 1){
                    if (isBlack(bmp[frontPos.x - 1][frontPos.y])) {
                        bmp[frontPos.x - 1][frontPos.y] = usedRGB;
                        pixelsProcessed.push(upP);
                    }
                    if (isBlack(bmp[frontPos.x + 1][frontPos.y])) {
                        bmp[frontPos.x + 1][frontPos.y] = usedRGB;
                        pixelsProcessed.push(downP);
                    }
                    if (isBlack(bmp[frontPos.x][frontPos.y - 1])) {
                        bmp[frontPos.x][frontPos.y - 1] = usedRGB;
                        pixelsProcessed.push(leftP);
                    }
                }
            } else if (frontPos.x == 0){
                if (frontPos.y > 0 && frontPos.y < bmp[0].size() - 1) {
                    if (isBlack(bmp[frontPos.x + 1][frontPos.y])) {
                        bmp[frontPos.x + 1][frontPos.y] = usedRGB;
                        pixelsProcessed.push(downP);
                    }
                    if (isBlack(bmp[frontPos.x][frontPos.y - 1])) {
                        bmp[frontPos.x][frontPos.y - 1] = usedRGB;
                        pixelsProcessed.push(leftP);
                    }
                    if (isBlack(bmp[frontPos.x][frontPos.y + 1])) {
                        bmp[frontPos.x][frontPos.y + 1] = usedRGB;
                        pixelsProcessed.push(rightP);
                    }
                } else if (frontPos.y == 0){
                    if (isBlack(bmp[frontPos.x+1][frontPos.y])) {
                        bmp[frontPos.x+1][frontPos.y] = usedRGB;
                        pixelsProcessed.push(downP);
                    }
                    if (isBlack(bmp[frontPos.x][frontPos.y+1])) {
                        bmp[frontPos.x][frontPos.y + 1] = usedRGB;
                        pixelsProcessed.push(rightP);
                    }
                } else if (frontPos.y == bmp[0].size() - 1){
                    if (isBlack(bmp[frontPos.x + 1][frontPos.y])) {
                        bmp[frontPos.x + 1][frontPos.y] = usedRGB;
                        pixelsProcessed.push(downP);
                    }
                    if (isBlack(bmp[frontPos.x][frontPos.y - 1])) {
                        bmp[frontPos.x][frontPos.y - 1] = usedRGB;
                        pixelsProcessed.push(leftP);
                    }
                }
            } else if (frontPos.x == bmp.size() - 1){
                if (frontPos.y > 0 && frontPos.y < bmp[0].size() - 1) {
                    if (isBlack(bmp[frontPos.x - 1][frontPos.y])) {
                        bmp[frontPos.x - 1][frontPos.y] = usedRGB;
                        pixelsProcessed.push(upP);
                    }
                    if (isBlack(bmp[frontPos.x][frontPos.y - 1])) {
                        bmp[frontPos.x][frontPos.y - 1] = usedRGB;
                        pixelsProcessed.push(leftP);
                    }
                    if (isBlack(bmp[frontPos.x][frontPos.y + 1])) {
                        bmp[frontPos.x][frontPos.y + 1] = usedRGB;
                        pixelsProcessed.push(rightP);
                    }
                } else if (frontPos.y == 0){
                    if (isBlack(bmp[frontPos.x-1][frontPos.y])) {
                        bmp[frontPos.x-1][frontPos.y] = usedRGB;
                        pixelsProcessed.push(upP);
                    }
                    if (isBlack(bmp[frontPos.x][frontPos.y+1])) {
                        bmp[frontPos.x][frontPos.y + 1] = usedRGB;
                        pixelsProcessed.push(rightP);
                    }
                } else if (frontPos.y == bmp[0].size() - 1){
                    if (isBlack(bmp[frontPos.x - 1][frontPos.y])) {
                        bmp[frontPos.x - 1][frontPos.y] = usedRGB;
                        pixelsProcessed.push(upP);
                    }
                    if (isBlack(bmp[frontPos.x][frontPos.y - 1])) {
                        bmp[frontPos.x][frontPos.y - 1] = usedRGB;
                        pixelsProcessed.push(leftP);
                    }
                }
            }
            pixelsProcessed.pop();
        }
    }
    return pixelsFound;
}

int main()
{
    Bitmap image;
    vector < vector <Pixel> > bmp;
    vector < vector <Position> > letterObjects;
    Pixel rgb;

    //read a file example.bmp and convert it to a pixel matrix
    image.open("myInput0.bmp");

    //verify that the file opened was a valid image
    bool validBmp = image.isImage();

    if( validBmp == true )
    {
        bmp = image.toPixelMatrix();
        for (unsigned int i=0;i<bmp.size();i++){
            for (unsigned int j=0;j<bmp[i].size();j++){
                if (isBlack(bmp[i][j])){
                    Position lookfor(i,j);
                    letterObjects.push_back(addFrom(bmp,lookfor));
                }
            }
        }
        image.fromPixelMatrix(bmp);
        image.save("cleanResult.bmp");
        for (auto letObject:letterObjects){
            Pixel randomRGB = get_random_pixel();
            for (Position p: letObject){
                bmp[p.x][p.y] = randomRGB;
            }
        }
        image.fromPixelMatrix(bmp);
        image.save("colorResult.bmp");
    }
    return 0;
}
