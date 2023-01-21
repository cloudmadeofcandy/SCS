#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
using namespace std;
int BusCut[100][100];
// ma trận kề của các tuyến xe bus
int StopPoint[100][100];
// ma trận điểm dừng
int VSBus[100];
// mảng visit dùng Q
int N, M, Q;
void createBusCut()
{
    // khởi tạo ma trận kề
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            BusCut[i][j] = 0;
        }
    }
    for (int point = 1; point <= M; point++)
    {
        int numberBus = StopPoint[point][0];
        // số xe bus tại điểm dừng
        for (int i = 1; i < numberBus; i++)
        {
            for (int j = i + 1; j < numberBus + 1; j++)
            {
                int busStart = StopPoint[point][i];
                int busEnd = StopPoint[point][j];
                BusCut[busStart][busEnd] = 1;
                BusCut[busEnd][busStart] = 1;
            }
        }
    }
}
int checkRoad(int start, int end)
{
    for (int j = 0; j < 100; j++)
    {
        VSBus[j] = 0;
    }
    int QBus[100];
    int front, rear;
    front = 0;
    rear = 0;
    for (int i = 1; i <= StopPoint[start][0]; i++)
    {
        QBus[rear] = StopPoint[start][i];
        VSBus[QBus[rear]] = 1;
        rear++;
    }
    while (front < rear)
    {
        int busCurrent = QBus[front];
        front++;
        for (int i = 1; i <= StopPoint[end][0]; i++)
        {
            if (busCurrent == StopPoint[end][i])
            {
                return VSBus[busCurrent];
            }
        }
        if (VSBus[busCurrent] >= 3)
            continue;
        for (int busConnect = 0; busConnect <= N; busConnect++)
        {
            if (BusCut[busCurrent][busConnect] == 1 && VSBus[busConnect] == 0)
            {
                VSBus[busConnect] = VSBus[busCurrent] + 1;
                QBus[rear] = busConnect;
                rear++;
            }
        }
    }
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T = 10;
    cin >> T;
    int L;
    int point;
    int startPoint, endPoint;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> N >> M >> Q;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j <= N; j++)
            {
                StopPoint[i][j] = 0;
            }
        }
        for (int busi = 1; busi <= N; busi++)
        {
            cin >> L;
            // số điểm dừng của busi
            for (int j = 0; j < L; j++)
            {
                cin >> point;
                //điểm dừng thứ j
                StopPoint[point][0]++;
                // tăng số lượng xe bus đi qua điểm dừng point
                int index = StopPoint[point][0];
                StopPoint[point][index] = busi;
            }
        }
        createBusCut();
        cout << "Case #" << tc << " ";
        for (int i = 0; i < Q; i++)
        {
            cin >> startPoint >> endPoint;
            int number = checkRoad(startPoint, endPoint);
            cout << number << " ";
        }
        cout << endl;
    }
    return 0;
}