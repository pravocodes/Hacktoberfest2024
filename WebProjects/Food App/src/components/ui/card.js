const Card = ({ children, className }) => {
    return (
      <div className={`p-4 border rounded-lg shadow-md ${className}`}>
        {children}
      </div>
    );
  };
  
  const CardHeader = ({ children }) => {
    return <div className="mb-2">{children}</div>;
  };
  
  const CardContent = ({ children }) => {
    return <div>{children}</div>;
  };
  
  const CardFooter = ({ children }) => {
    return <div className="mt-4">{children}</div>;
  };
  
  const CardTitle = ({ children }) => {
    return <h3 className="text-lg font-bold">{children}</h3>;
  };
  
  export { Card, CardHeader, CardContent, CardFooter, CardTitle };
  