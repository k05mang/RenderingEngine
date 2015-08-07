
class BufferObject
{
    private:
        Gluint bufferId;
    public:
        BufferObject(GLenum bufferTarget);
        ~BufferObject();

        void bind();
        void unbind();
        void erase();
        void add(vector<int> values);
};
