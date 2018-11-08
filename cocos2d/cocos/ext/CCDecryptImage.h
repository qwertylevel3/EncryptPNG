#ifndef __CC_DECRYPT_IMAGE_H__
#define __CC_DECRYPT_IMAGE_H__

#include <array>
#include <vector>
#include "CCData.h"
#include "CCAES.h"

namespace ext
{
    /* 解密扩展名 */
    static std::string TARGET_EXTENSION = ".fox";
    
    /* 解密密钥 */
    static aes_key SECRET_KEY = { 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39 };
    
    /**
     * 设置解密秘钥
     * @param key   秘钥（AES的16位秘钥）
     * @param exten 文件扩展名（需要解密的文件扩展名，如".png"）
     */
    void DecryptImageConfig(const aes_key &key, const std::string &exten = TARGET_EXTENSION);
    
	/**
	 * 解密图片文件（在CCImage中调用）
	 * @param filename 文件名称
	 * @param data 文件数据
	 */
    std::vector<unsigned char> DecryptImage(const std::string &filename, cocos2d::Data &data);
    
    /**
     * 分解文件名的扩展名（在CCImage中调用）
     * @param file_path 文件名
     */
    std::array<std::string, 2> AnalyzeExtension(const std::string &file_path);
    
}

#endif