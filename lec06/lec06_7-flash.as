package
{
    import flash.display.Sprite;
    import flash.utils.ByteArray;
    import flash.external.ExternalInterface;
    
    public class Main extends Sprite
    {
        public function Main()
        {

            var xxx:ByteArray = new ByteArray;
            xxx.length = 0x1000;
            xxx.writeUTFBytes("It's buffer");

            var va:Vector.<Object> = new <Object>[1, "Volvo", xxx];
            for (var i:int = va.length; i < 10; i++)
                va[i] = 0xdeadf00d;

            ExternalInterface.call('alert', 'Let\'s trace the ByteArray object..');
        }
    }
}