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

            var va:Vector.<Object> = new <Object>[0x2222222, "Volvo", xxx];

            ExternalInterface.call('alert', 'Let\'s trace the ByteArray object..');
        }
    }
}