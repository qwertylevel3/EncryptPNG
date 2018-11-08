# EncryptPNG
png加密解密

参考：
https://blog.csdn.net/ldpjay/article/details/46454999


## 用法：
1. 在 cocos 目录下新建文件夹 ext ，将 CCAES.cpp、CCAES.h、CCDecryptImage.cpp、CCDecryptImage.h 拷贝到其中。

2. IDE中将ext目录加入搜索

3. CCImage.cpp:

```
bool Image::initWithImageFile(const std::string& path)
{
    ......

    if (!data.isNull())
    {
        // 图片文件解密
        if (ext::AnalyzeExtension(path)[1] == ext::TARGET_EXTENSION)
		{
			auto image_data = ext::DecryptImage(path, data);
			ret = initWithImageData(&image_data[0], image_data.size());
		}
		else
		{
			ret = initWithImageData(data.getBytes(), data.getSize());
		}
    }
#endif // EMSCRIPTEN

    return ret;
}

bool Image::initWithImageFileThreadSafe(const std::string& fullpath)
{
    ......

    if (!data.isNull())
    {
        // 图片文件解密
        if (ext::AnalyzeExtension(fullpath)[1] == ext::TARGET_EXTENSION)
		{
            auto image_data = ext::DecryptImage(fullpath, data);
			ret = initWithImageData(&image_data[0], image_data.size());
		}
		else
		{
			ret = initWithImageData(data.getBytes(), data.getSize());
		}
    }

    return ret;
}
```

4. 密钥和扩展名可以在CCDecryptImage.h中设置：
```
......

namespace ext
{
    /* 解密扩展名 */
    static std::string TARGET_EXTENSION = ".epng";

    /* 解密密钥 */
    //如果用附带的工具加密的时候输入的是8888888888888888的话，则密钥可以设置如下
    static aes_key SECRET_KEY = { '8', '8','8','8','8', '8','8','8','8', '8','8','8','8', '8','8','8'};

    ......
}

...
```
