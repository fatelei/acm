#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

void utils(string data, char *rst) {
    int start = 0;
    for (string::iterator it = data.begin(); it != data.end(); it++) {
        if (*it == ' ') {
            continue;
        } else {
            if (*it == '0') {
                for (int i = 0; i < 4; i++) {
                    rst[start++] = '0';
                }
            } else {
                char binary[10];
                int index = 0;
                int target = 0;
                if (*it >= 'a' && *it <= 'f') {
                    target = (*it - 'a') + 10;
                } else {
                    target = *it - '0';
                }
                int binary_length = 0;
                while (target) {
                    binary[index++] = (target%2) + '0';
                    target /= 2;
                }
                binary[index] = '\0';
                binary_length = strlen(binary);
                if (binary_length != 4) {
                    for (int i = 0; i < 4 - binary_length; i++) {
                        binary[index++] = '0';
                    }
                    binary[index] = '\0';
                }
                binary_length = strlen(binary);
                for (int i = binary_length - 1; i >= 0; i--) {
                    rst[start++] = binary[i];
                }
            }
        }
    }
    rst[start] = '\0';
    return;
}

void process_length(string length) {
    char tmp[40];
    int tmp_length = 0;
    int result = 0;
    int p = 0;
    memset(tmp, '\0', sizeof(tmp));
    utils(length, tmp);
    tmp_length = strlen(tmp);
    for (int i = tmp_length - 1; i >= 0; i--) {
        result += (tmp[i] - '0') << p;
        p++;
    }
    printf("Total length = %d bytes\n", result);
}

void process_ip(string ip, int flag) {
    char tmp[40];
    char ipstr[40];
    string s;
    int result = 0;
    int tmp_length = 0;
    int p = 7;
    int i;
    memset(tmp, '\0', sizeof(tmp));
    memset(ipstr, '\0', sizeof(ipstr));
    utils(ip, tmp);
    tmp_length = strlen(tmp);
    for (i = 0; i < tmp_length; i++) {
        if (i && i%8 == 0) {
            int index = 0;
            while (result) {
                ipstr[index++] = (result%10) + '0';
                result /= 10;
            }
            ipstr[index] = '\0';
            for (int j = strlen(ipstr) - 1; j >= 0; j--) {
                s += ipstr[j];
            }
            s = s + ".";
            p = 7;
            result = 0;
            result += (tmp[i] - '0') << p;
            p--;
        } else {
            result += (tmp[i] - '0') << p;
            p--;
        }
    }
    result += (tmp[i] - '0') << p;
    sprintf(ipstr, "%d", result);
    s = s + ipstr;
    if (flag) {
        printf("Source = %s\n", s.c_str());
    } else {
        printf("Destination = %s\n", s.c_str());
    }
}

void process_port(string port, int flag) {
    char tmp[40];
    int result = 0;
    int p = 0;
    int tmp_length = 0;
    memset(tmp, '\0', sizeof(tmp));
    utils(port, tmp);
    tmp_length = strlen(tmp);
    for (int i = tmp_length - 1; i >= 0; i--) {
        result += (tmp[i] - '0') << p;
        p++;
    }
    if (flag) {
        printf("Source Port = %d\n", result);
    } else {
        printf("Destination Port = %d\n", result);
    }
}


void decode(string packet) {
    const char *tmp = packet.substr(1, 1).c_str();
    int ip_header = 0;
    if (*tmp >= 'a' && *tmp <= 'z') {
        ip_header = (*tmp - 'a') + 10;
    } else {
        ip_header = *tmp - '0';
    }
    ip_header = ip_header * 12;
    string length = packet.substr(6, 5);
    string source_ip = packet.substr(36, 11);
    string dest_ip = packet.substr(48, 11);
    string source_port = packet.substr(ip_header, 5);
    string dest_port = packet.substr(ip_header, 5);
    process_length(length);
    process_ip(source_ip, 1);
    process_ip(dest_ip, 0);
    process_port(source_port, 1);
    process_port(dest_port, 0);
}

int main() {
    int cases;
    string packet;
    scanf("%d", &cases);
    getchar();
    for (int i = 1; i <= cases; i++) {
        getline(cin, packet);
        printf("Case #%d\n", i);
        decode(packet);
        printf("\n");
    }
    return 0;
}
